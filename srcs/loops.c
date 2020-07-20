/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:21:44 by hgreenfe          #+#    #+#             */
/*   Updated: 2020/06/24 17:21:47 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		event_loop(void *game)
{
	SDL_Event	event;
	int			game_time;

	game_time = SDL_GetTicks();
	while (((t_game*)game)->state != G_QUIT)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				((t_game*)game)->state = G_QUIT;
				break ;
			}
			pool_all_events(game, &event);
		}
		if ((SDL_GetTicks() - game_time) > TIMEOUT_MILISEC)
		{
			((t_game*)game)->fps = 1000.0 / (SDL_GetTicks() - game_time);
			game_time = SDL_GetTicks();
			process_game(game);
		}
		render_game(game);
	}
	return (NO_ERR);
}
