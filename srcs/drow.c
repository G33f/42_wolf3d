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

void	draw(t_data *p, int i, int column_h)
{
	int	space;
	int r;

	r = 0;
	space = (p->mlx.win_y_size - column_h) / 2;
	while(r < (int)column_h || (r + 1 + space) < p->mlx.win_y_size)
	{
		p->mlx.img_data[i*2 + (r + space) * p->mlx.win_x_size] = 0xFFFFFF;
		p->mlx.img_data[i*2 + 1 + (r + space) * p->mlx.win_x_size] = 0xFFFFFF;
		r++;
	}
}

void	casting(t_data *p, float angel, int i)
{
	float	t;
	float	cx;
	float	cy;
	int	column_h;

	t = 0;
	while(t < 20.0)
	{
		cx = p->ply.x + t * cos(angel);
		cy = p->ply.y + t * sin(angel);
		if (p->map.map[(int)cx][(int)cy] != '0')
		{
			column_h = p->mlx.win_y_size/t;
			draw(p, i, column_h);
			return;
		}
		t += 0.05;
	}
}

void	render(t_data *p)
{
	float	angle;
	int	i;

	i = 0;
	while (i < p->mlx.win_x_size/2)
	{
		angle = p->ply.a - p->ply.fov / 2 + p->ply.fov * i / (float)(p->mlx.win_x_size /2);
		casting(p, angle, i);
		i++;
	}
}