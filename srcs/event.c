/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <hgreenfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 16:16:00 by hgreenfe          #+#    #+#             */
/*   Updated: 2020/06/14 15:07:13 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

int		event_keyup(SDL_Event *event, t_game *game)
{
	int		err;

	err = NO_ERR;
	if (game->state == G_PROCESS)
		err = event_keyup_process(event, game);
	else if (game->state == G_MENU)
		err = event_keyup_menu(event, game);
	else if (game->state == G_EDITOR)
		err = event_keyup_editor(event, game);
	if (event->key.keysym.sym == SDLK_ESCAPE && game->state != G_MENU
		&& game->state != G_QUIT)
		game->state = G_MENU;
	return (err);
}

int		event_keydown(SDL_Event *event, t_game *game)
{
	if (event->key.keysym.sym == SDLK_w)
		game->player->move = PM_FRONT;
	if (event->key.keysym.sym == SDLK_s)
		game->player->move = PM_BACK;
	if (event->key.keysym.sym == SDLK_d)
		game->player->move = PM_RIGHT;
	if (event->key.keysym.sym == SDLK_a)
		game->player->move = PM_LEFT;
	return (NO_ERR);
}

int		event_mouse(SDL_Event *event, t_game *game)
{
	int		err;

	err = NO_ERR;
	if (game->state == G_PROCESS)
		err = (event_mouse_process(event, game));
	if (game->state == G_MENU)
		err = (event_mouse_menu(event, game));
	if (game->state == G_EDITOR)
		err = (event_mouse_editor(event, game));
	if (event->type == SDL_MOUSEMOTION)
	{
		game->mouse->x = event->motion.x;
		game->mouse->y = event->motion.y;
	}
	else
	{
		game->mouse->x = event->button.x;
		game->mouse->y = event->button.y;
		if (event->type == SDL_MOUSEBUTTONUP)
			game->mouse->button &= SDL_BUTTON(~event->button.button);
		else
			game->mouse->button |= SDL_BUTTON(event->button.button);
	}
	return (err);
}

void	pool_all_events(t_game *game, SDL_Event *event)
{
	if (event->type == SDL_KEYUP)
		event_keyup(event, game);
	if (event->type == SDL_KEYDOWN)
		event_keydown(event, game);
	if (event->type == SDL_MOUSEMOTION || event->type == SDL_MOUSEBUTTONUP
		|| event->type == SDL_MOUSEBUTTONDOWN)
		event_mouse(event, game);
}
