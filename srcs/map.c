/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <hgreenfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 16:20:21 by hgreenfe          #+#    #+#             */
/*   Updated: 2020/06/13 19:21:25 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"
#include <math.h>

unsigned int	get_color(unsigned char type)
{
	return ((type & 0x1u) |
		((255u * ((type & 0x2u) >> 1u)) << 8u) |
		((255u * ((type & 0x4u) >> 2u)) << 16u) |
		(0xffu << 24u));
}

void			render_rect(t_game *game, char type, int x, int y)
{
	SDL_Rect rect;
	unsigned color;

	rect.x = x * SIZE_RECT;
	rect.y = y * SIZE_RECT;
	rect.w = SIZE_RECT;
	rect.h = SIZE_RECT;
	color = get_color(type);
	fill_rect(game->pixels, game->rect, &rect, color);
}

void			render_start_end(t_game *game)
{
	SDL_Rect	startpos;
	SDL_Rect	endpos;

	startpos.x = (game->level->startpos % game->level->size_x) * SIZE_RECT;
	startpos.y = (game->level->startpos / game->level->size_x) * SIZE_RECT;
	startpos.w = SIZE_RECT;
	startpos.h = SIZE_RECT;
	endpos.x = (game->level->endpos % game->level->size_x) * SIZE_RECT;
	endpos.y = (game->level->endpos / game->level->size_x) * SIZE_RECT;
	endpos.w = SIZE_RECT;
	endpos.h = SIZE_RECT;
	fill_rect(game->pixels, game->rect, &startpos, 0xa0a0a0ffu);
	fill_rect(game->pixels, game->rect, &endpos, 0x90909090u);
}

void			render_watch(t_game *game)
{
	SDL_Rect	r;

	r.x = (int)(game->player->pos_x * SIZE_RECT);
	r.y = (int)(game->player->pos_y * SIZE_RECT);
	r.w = (int)(SIZE_RECT * (game->player->pos_x + game->player->watch_x));
	r.h = (int)(SIZE_RECT * (game->player->pos_y + game->player->watch_y));
	draw_line(game->pixels, game->rect, &r, 0xffffffff);
}

void			render_map(t_game *game)
{
	int			i;

	i = 0;
	while (i < game->level->size_x * game->level->size_y)
	{
		render_rect(game, (char)(game->level->array[i] & 0xff),
					i % game->level->size_x, i / game->level->size_x);
		++i;
	}
	render_start_end(game);
	render_watch(game);
}
