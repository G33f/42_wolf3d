/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <hgreenfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 16:13:40 by hgreenfe          #+#    #+#             */
/*   Updated: 2020/06/14 16:31:23 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"

int		create_payer(t_game *game)
{
	numeric		size;

	size = 1.0;
	game->player = ft_memalloc(sizeof(t_player));
	game->player->pos_x = (game->level->startpos % game->level->size_x) * size;
	game->player->pos_x += size / 2;
	game->player->pos_y = (game->level->startpos / game->level->size_x) * size;
	game->player->pos_y += size / 2;
	game->player->prev_mouse_x = 0;
	game->player->watch_x = 1.0;
	game->player->watch_y = 0.0;
	return (NO_ERR);
}

void	move_player(t_game *game, numeric speed_x, numeric speed_y)
{
	int		next_x;
	int		next_y;

	next_x = (int)(game->player->pos_x + speed_x);
	next_y = (int)(game->player->pos_y + speed_y);
	if ((next_x != (int)game->player->pos_x)
	|| (next_y != (int)game->player->pos_y))
	{
		if (game->level->array[next_x + next_y * game->level->size_x])
			return ;
	}
	game->player->pos_x += speed_x;
	game->player->pos_y += speed_y;
}

void	destroy_player(t_game *game)
{
	ft_bzero((game->player), sizeof(t_player));
	ft_memdel((void**)&(game->player));
}
