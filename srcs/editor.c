/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <hgreenfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 11:40:03 by hgreenfe          #+#    #+#             */
/*   Updated: 2020/06/14 13:13:55 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		event_keyup_editor(SDL_Event *event, t_game *game)
{
	(void)event;
	(void)game;
	return (NO_ERR);
}

void	set_map_type(const t_game *game, int i, int j)
{
	SDL_Rect	rect;
	SDL_Point	p;

	rect = create_rect(j * EDITOR_SIZE_RECT, i * EDITOR_SIZE_RECT,
		EDITOR_SIZE_RECT, EDITOR_SIZE_RECT);
	p = set_to(game->mouse->x, game->mouse->y);
	if (SDL_PointInRect(&p, &rect))
	{
		if (game->level->array[j + i * game->level->size_x])
			game->level->array[j + i * game->level->size_x] = 0;
		else
			game->level->array[j + i * game->level->size_x] = 7;
	}
}

int		event_mouse_editor(SDL_Event *event, t_game *game)
{
	int			i;
	int			j;

	if (event->type == SDL_MOUSEBUTTONUP)
	{
		i = -1;
		while (++i < game->level->size_y)
		{
			j = -1;
			while (++j < game->level->size_x)
			{
				if (event->button.button)
					set_map_type(game, i, j);
			}
		}
	}
	return (NO_ERR);
}

void	render_editor_game(t_game *game)
{
	int			i;
	int			j;
	SDL_Rect	rect;

	i = 0;
	rect = create_rect(0, 0, game->level->size_x * EDITOR_SIZE_RECT,
		game->level->size_y * EDITOR_SIZE_RECT);
	fill_rect(game->pixels, game->rect, &rect, 0x90909090);
	while (i < game->level->size_y)
	{
		j = 0;
		while (j < game->level->size_x)
		{
			if (game->level->array[j + i * game->level->size_x])
			{
				rect = create_rect(j * EDITOR_SIZE_RECT, i * EDITOR_SIZE_RECT,
						EDITOR_SIZE_RECT, EDITOR_SIZE_RECT);
				fill_rect(game->pixels, game->rect, &rect, 0xffffffff);
			}
			++j;
		}
		++i;
	}
}

void	process_editor_game(t_game *game)
{
	(void)game;
}
