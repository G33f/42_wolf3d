/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <hgreenfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 16:23:33 by hgreenfe          #+#    #+#             */
/*   Updated: 2020/06/22 00:37:11 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

void	draw(t_game *game, int i, numeric dist, t_ray *ray)
{
	int				space;
	int				y;
	int				line_height;
	unsigned int	color;

	if (dist <= 1.0)
		line_height = game->rect->h;
	else
		line_height = (int)(game->rect->h / (dist));
	y = 0;
	space = (game->rect->h - line_height) / 2;
	while (y < line_height && (y + 1 + space) < game->rect->h)
	{
		color = get_wall_color(ray, game,
			y + ((game->rect->h / (dist)) - line_height) / 2,
			(game->rect->h / (dist)));
		(game->pixels)[i + (y + space) * game->rect->w] =
			get_color_by_len(color, dist, MAX_DISTANCE);
		y++;
	}
}

void	start_ray(t_game *game, t_ray *ray, int x)
{
	numeric		camera_x;
	numeric		plane_x;
	numeric		plane_y;

	camera_x = (x << 1) / (double)game->rect->w - 1;
	plane_x = -game->player->watch_y;
	plane_y = game->player->watch_x;
	ray->dir_x = game->player->watch_x + plane_x * camera_x;
	ray->dir_y = game->player->watch_y + plane_y * camera_x;
	ray->map_x = (int)game->player->pos_x;
	ray->map_y = (int)game->player->pos_y;
	ray->dist_x = 0.0;
	ray->dist_y = 0.0;
	ray->delta_x = fabs(1 / ray->dir_x);
	ray->delta_y = fabs(1 / ray->dir_y);
	ray->perp_wall_dist = 0.0;
	ray->hit = 0;
	ray->side = 0;
}

void	step_check(t_game *game, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->dist_x = (game->player->pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->dist_x = (ray->map_x + 1.0 - game->player->pos_x) * ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->dist_y = (game->player->pos_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->dist_y = (ray->map_y + 1.0 - game->player->pos_y) * ray->delta_y;
	}
}

int		render(t_game *game)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < game->rect->w)
	{
		start_ray(game, &ray, x);
		step_check(game, &ray);
		casting(game, &ray);
		if (ray.side)
			ray.perp_wall_dist = (ray.map_y - game->player->pos_y +
				((1 - ray.step_y) >> 1)) / ray.dir_y;
		else
			ray.perp_wall_dist = (ray.map_x - game->player->pos_x +
				((1 - ray.step_x) >> 1)) / ray.dir_x;
		draw(game, x, ray.perp_wall_dist, &ray);
		x++;
	}
	return (NO_ERR);
}
