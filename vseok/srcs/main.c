/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <hgreenfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:17:49 by hgreenfe          #+#    #+#             */
/*   Updated: 2020/03/15 15:30:59 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SDL_MAIN_HANDLED

#include "libft.h"
#include "SDL2/SDL.h"
#include "wolf3d.h"
#include <math.h>
#include <stdio.h>

#define SIZE_RECT           20

#define TIMEOUT_MILISEC     1000
#define FOV 				(3.14159 / 3.0)


int event_keyup(SDL_Event *event, t_game *game)
{
	if (event->key.keysym.sym == SDLK_ESCAPE)
		game->state = G_QUIT;
	return (NO_ERR);
}

int event_keydown(SDL_Event *event, t_game *game)
{
	(void) event;
	(void) game;
	return (NO_ERR);
}

int event_mouse(SDL_Event *event, t_game *game)
{
	(void) event;
	(void) game;

	if (event && event->type == SDL_MOUSEMOTION)
	{
		if (event->motion.xrel != 0)
		{
			game->player->watch_x += event->motion.xrel * 0.25;
		}
	}
	return (NO_ERR);
}


void	draw(t_game *game, int **pixels, int i, int column_h)
{
	int	space;
	int r;

	r = 0;
	space = (game->rect->h - column_h) / 2;
	while(r < column_h && (r + 1 + space) < game->rect->h)
	{
		(*pixels)[i*2 + (r + space) * game->rect->w] = 0xFFFFFF;
		(*pixels)[i*2 + 1 + (r + space) * game->rect->w] = 0xFFFFFF;
		r++;
	}
}

void	casting(t_game *game, int **pixels, double angle, int i)
{
	double	t;
	double	cx;
	double	cy;
	int		column_h;

	t = 0.05;
	while (t < 20.0)
	{
		cx = game->player->pos_x + t * cos(angle);
		cy = game->player->pos_y + t * sin(angle);
		if (game->level->array[(int)cx + (int)cy * game->level->size_x] != 0)
		{
			column_h = (int)(game->rect->h / t);
			draw(game, pixels, i, column_h);
			return;
		}
		t += 0.05;
	}
}

void	render(t_game *game, int **pixels)
{
	double angle;
	int	i;

	i = 0;
	while (i < game->rect->w/ 2)
	{
		angle = game->player->watch_x - (FOV / 2.0)
			+ (FOV * i / (double)(game->rect->w / 2));
		casting(game, pixels, angle, i);
		i++;
	}
}

int render_level(t_game *game)
{
	int			*pixels;
	int			pitch;

	SDL_LockTexture(game->texture, NULL, (void **) &pixels, &pitch);
	render(game, &pixels);
	SDL_UnlockTexture(game->texture);
	SDL_RenderCopy(game->rnd, game->texture, NULL, game->rect);
	return (NO_ERR);
}

void render_rect(t_game *game, char type, int x, int y)
{
	SDL_Rect rect;

	rect.x = x * SIZE_RECT;
	rect.y = y * SIZE_RECT;
	rect.w = SIZE_RECT;
	rect.h = SIZE_RECT;
	SDL_SetRenderDrawColor(game->rnd,
						   type & 0x1u, 255 * ((type & 0x2u) >> 1),
						   255 * ((type & 0x4u) >> 2), 0xff);
	SDL_RenderFillRect(game->rnd, &rect);
}

void render_map(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->level->size_x * game->level->size_y)
	{
		render_rect(game, (char) (game->level->array[i] & 0xff),
					i % game->level->size_x, i / game->level->size_x);
		++i;
	}
}

void render_game(t_game *game)
{
	SDL_SetRenderDrawColor(game->rnd, 0, 0, 0, 0);
	SDL_RenderClear(game->rnd);
	render_level(game);
	// render_map(game);
	SDL_RenderPresent(game->rnd);
}

void process_game(t_game *game)
{
	(void) game;
}

void event_loop(t_game *game)
{
	SDL_Event event;
	int game_time;

	game_time = SDL_GetTicks();
	while (game->state != G_QUIT)
	{
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				break;
			if (event.type == SDL_KEYUP)
				event_keyup(&event, game);
			if (event.type == SDL_KEYDOWN)
				event_keydown(&event, game);
			if (event.type == SDL_MOUSEMOTION)
				event_mouse(&event, game);
		}
		if (SDL_GetTicks() - game_time > TIMEOUT_MILISEC)
		{
			game_time = SDL_GetTicks();
			process_game(game);
		}
		render_game(game);
	}
}

int create_window(t_game *game)
{
	game->rect = ft_memalloc(sizeof(SDL_Rect));
	if (!game->rect)
		return (MEM_ERR);
	game->rect->x = 0;
	game->rect->y = 0;
	game->rect->w = WIN_SIZE_W;
	game->rect->h = WIN_SIZE_H;
	game->wnd = SDL_CreateWindow(WIN_TITLE,
								 WIN_POS_X, WIN_POS_Y, WIN_SIZE_W, WIN_SIZE_H,
								 SDL_WINDOW_RESIZABLE);
	if (!game->wnd)
	{
		ft_putendl("wnd doesn't create");
		return (SDL_ERR);
	}
	game->surface = SDL_GetWindowSurface(game->wnd);
	game->rnd = SDL_CreateSoftwareRenderer(game->surface);
	if (!game->rnd)
	{
		ft_putendl("render  doesn't create");
		ft_putendl(SDL_GetError());
		return (SDL_ERR);
	}
	game->texture = SDL_CreateTexture(game->rnd,
									  SDL_PIXELFORMAT_RGBA8888,
									  SDL_TEXTUREACCESS_STREAMING, WIN_SIZE_W,
									  WIN_SIZE_H);
	if (!game->texture)
	{
		ft_putendl("texture doesn't create");
		return (SDL_ERR);
	}
	SDL_SetRelativeMouseMode(1);
	return (NO_ERR);
}

int destroy_window(t_game *game)
{
	SDL_SetRelativeMouseMode(0);
	SDL_DestroyTexture(game->texture);
	SDL_DestroyRenderer(game->rnd);
	SDL_DestroyWindow(game->wnd);
	ft_memdel((void **) &(game->rect));
	return (0);
}

int create_payer(t_game *game)
{
	numeric		size;

	size = game->rect->h;
	game->player = ft_memalloc(sizeof(t_player));
	game->player->pos_x = (game->level->startpos % game->level->size_x) * size;
	game->player->pos_y = (game->level->startpos / game->level->size_x) * size;
	return (NO_ERR);
}

int main(int argc, char **argv)
{
	t_game *game;

	SDL_Init(SDL_INIT_VIDEO);
	game = (t_game *) ft_memalloc(sizeof(*game));
	if (argc > 1)
		game->level = load_map_from_file(argv[1]);
	else
		return (0);
	if (create_window(game) != NO_ERR)
		return (SDL_ERR);
	if (create_payer(game) != NO_ERR)
		return (PLY_ERR);
	game->state = G_MENU;
	event_loop(game);
	destroy_window(game);
	ft_memdel((void **) &game);
	SDL_Quit();
	return (0);
}
