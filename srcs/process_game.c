/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <hgreenfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:32:15 by hgreenfe          #+#    #+#             */
/*   Updated: 2020/06/19 21:56:47 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

int		event_keyup_process(SDL_Event *event, t_game *game)
{
	if (event->key.keysym.sym == SDLK_ESCAPE)
	{
		game->state = G_MENU;
		SDL_ShowCursor(1);
	}
	if (event->key.keysym.sym == SDLK_t && game->walls)
		game->walls->enabled = !game->walls->enabled;
	if ((event->key.keysym.sym == SDLK_w)
		|| (event->key.keysym.sym == SDLK_s)
		|| (event->key.keysym.sym == SDLK_d)
		|| (event->key.keysym.sym == SDLK_a))
		game->player->move = PM_NONE;
	return (NO_ERR);
}

int		event_mouse_process(SDL_Event *event, t_game *game)
{
	numeric			old_watch_x;
	numeric			speed;
	numeric const	player_rotate = PLAYER_ROTATE;

	if (event->type == SDL_MOUSEMOTION)
	{
		old_watch_x = game->player->watch_x;
		speed = (event->motion.x - game->player->prev_mouse_x) *
				player_rotate * game->fps;
		game->player->watch_x = game->player->watch_x * cos(speed)
								- game->player->watch_y * sin(speed);
		game->player->watch_y = old_watch_x * sin(speed)
								+ game->player->watch_y * cos(speed);
		game->player->prev_mouse_x = event->motion.x;
	}
	return (NO_ERR);
}

void	render_process_game(t_game *game)
{
	render(game);
	render_map(game);
}

void	process_process_game(t_game *game)
{
	if (game->player->move == PM_FRONT)
	{
		move_player(game, game->fps * PLAYER_MOVE * game->player->watch_x
			, game->fps * PLAYER_MOVE * game->player->watch_y);
	}
	else if (game->player->move == PM_BACK)
	{
		move_player(game, -game->fps * PLAYER_MOVE * game->player->watch_x
			, -game->fps * PLAYER_MOVE * game->player->watch_y);
	}
	if (game->player->move == PM_RIGHT)
	{
		move_player(game, -game->fps * PLAYER_MOVE * game->player->watch_y
			, game->fps * PLAYER_MOVE * game->player->watch_x);
	}
	else if (game->player->move == PM_LEFT)
	{
		move_player(game, game->fps * PLAYER_MOVE * game->player->watch_y
			, -game->fps * PLAYER_MOVE * game->player->watch_x);
	}
	game->player->move = PM_NONE;
}
