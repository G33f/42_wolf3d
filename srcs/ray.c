/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <hgreenfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 22:57:01 by hgreenfe          #+#    #+#             */
/*   Updated: 2020/06/20 01:22:45 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

unsigned int	get_color_by_type(int wall_type)
{
	if (wall_type == WEST_WALL)
		return (0xffff0000u);
	else if (wall_type == EAST_WALL)
		return (0xff00ff00u);
	else if (wall_type == NORTH_WALL)
		return (0xff0000ffu);
	else
		return (0xffffffffu);
}

unsigned int	get_wall_color(t_ray *ray, t_game *game,
		numeric y, numeric height)
{
	int				type;
	unsigned int	color;

	type = get_wall_type(ray, game);
	if (!game->walls || !game->walls->enabled)
		return (get_color_by_type(type));
	ray->wall_x -= (int)ray->wall_x;
	game->walls->num = type;
	color = get_texture_pixel(game->walls, ray->wall_x, y, height);
	return (color);
}

void			casting(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->dist_x < ray->dist_y)
		{
			ray->dist_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->dist_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if ((ray->map_x >= game->level->size_x)
			|| (ray->map_y >= game->level->size_y
			|| (ray->map_x < 0 || ray->map_y < 0))
			|| (game->level->array[ray->map_x +
					ray->map_y * game->level->size_x]))
			ray->hit = 1;
	}
}
