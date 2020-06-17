/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:28:01 by wpoudre           #+#    #+#             */
/*   Updated: 2020/06/12 16:41:43 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf3d.h"

void	draw(t_data *p, int i, int column_h, t_ray *ray)
{
	int			space;
	int			r;
	double		step;
	int			texY;
	double		texPos;
	t_textur	*t;

	r = 0;
	t = get_textur(ray->tex_nmb - 1, p);
	step = 1.0 * p->tex.h / column_h;
	space = (p->mlx.win_y_size - column_h) / 2;
	texPos = (space - p->mlx.win_y_size / 2 + column_h / 2) * step;
	while(r < column_h && (r + 1 + space) < p->mlx.win_y_size)
	{
		texY = (int)texPos & (p->tex.h - 1);
		texPos += step;
		p->mlx.img_data[i + (r + space) * p->mlx.win_x_size] = t->tex_data[p->tex.h * texY + ray->tex_x];
		r++;
	}
}

void	render_init(t_data *p, t_ray *ray, int x)
{
	ray->cameraX = 2 * x / (double)p->mlx.win_x_size - 1;
	ray->rayDirX = p->ply.dirX + p->ply.planeX * ray->cameraX;
	ray->rayDirY = p->ply.dirY + p->ply.planeY * ray->cameraX;
	ray->mapX = (int)p->ply.x;
	ray->mapY = (int)p->ply.y;
	ray->sideDistX = 0.0;
	ray->sideDistY = 0.0;
	ray->deltaDistX = fabs(1 / ray->rayDirX);
	ray->deltaDistY = fabs(1 / ray->rayDirY);
	ray->perpWallDist = 0.0;
	ray->hit = 0;
	ray->side = 0;
}

void	step_check(t_data *p, t_ray *ray)
{
	if(ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (p->ply.x - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - p->ply.x) * ray->deltaDistX;
	}
	if(ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (p->ply.y - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - p->ply.y) * ray->deltaDistY;
	}
}

void	casting(t_data *p, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if(ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if(p->map.map[ray->mapX][ray->mapY] != '0')
		{
			ray->hit = 1;
			ray->tex_nmb = p->map.map[ray->mapX][ray->mapY];
		}
	}
}

void	map_render(t_data *p)
{
	int		x;
	t_ray	ray;
	int		lineHeight;

	for(x = 0; x < p->mlx.win_x_size; x++)
	{
		render_init(p, &ray, x);
		step_check(p, &ray);
		casting(p, &ray);
		if(ray.side == 0)
			ray.perpWallDist = (ray.mapX - p->ply.x + (1 - ray.stepX) / 2) / ray.rayDirX;
		else
			ray.perpWallDist = (ray.mapY - p->ply.y + (1 - ray.stepY) / 2) / ray.rayDirY;
		if (ray.side == 0)
			ray.wall_x = p->ply.y + ray.perpWallDist * ray.rayDirY;
		else
			ray.wall_x = p->ply.x + ray.perpWallDist * ray.rayDirX;
		ray.wall_x -= floor((ray.wall_x));
		ray.tex_x = (int)(ray.wall_x * (double)p->tex.w);
		if(ray.side == 0 && ray.rayDirX > 0)
			ray.tex_x = p->tex.w - ray.tex_x - 1;
		if(ray.side == 1 && ray.rayDirY < 0)
			ray.tex_x = p->tex.w - ray.tex_x - 1;
		lineHeight = (int)(p->mlx.win_y_size / ray.perpWallDist);
		draw(p, x, lineHeight, &ray);
	}
}
