/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:28:01 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/08 15:28:04 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf3d.h"

void	draw(t_data *p, size_t i, size_t column_h)
{
	int	space;
	int r;

	r = 0;
	space = p->mlx.win_y_size - column_h;
	while(r < (int)column_h)
	{
		p->mlx.img_data[i + (r + space) * p->mlx.win_x_size] = 0xFFFFFF;
		p->mlx.img_data[i + 1 + (r + space) * p->mlx.win_x_size] = 0xFFFFFF;
	}
}

void	cast(t_data *p, float angel, size_t i)
{
	float	t;
	float	cx;
	float	cy;
	size_t	column_h;

	t = 0;
	while(t < 20.0)
	{
		cx = p->ply.x + t * cos(angel);
		cy = p->ply.y + t * sin(angel);
		if (p->map.map[int(cx)][int(cy)] != '0')
		{
			column_h = p->mlx.win_y_size/t;
			draw(p, i, column_h);
		}
		t += 0.05;
	}
}

void	render(t_data *p)
{
	float	angle;
	size_t	i;

	i = 0;
	for (i++ < p->mlx.win_x_size/2)
	{
		angle = p->ply.a - p->ply.fov / 2 + p->ply.fov * i / float(p->mlx.win_x_size /2);
		cast(p, angle, i);
	}
}