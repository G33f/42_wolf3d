/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:23:21 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/08 14:23:23 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	img_rebild(t_data *p)
{
	mlx_destroy_image(p->mlx.mlx, p->mlx.img);
	if(!(p->mlx.img = mlx_new_image(p->mlx.mlx, p->mlx.win_x_size, p->mlx.win_y_size)))
		error(-13);
	if(!(p->mlx.img_data = (int *)mlx_get_data_addr(p->mlx.img, &p->mlx.bit_per_pixel, &p->mlx.size_line
			, &p->mlx.endline)))
		error(-13);
}

void	init_mlx_params(t_data *p)
{
	p->mlx.win_x_size = 1024;
	p->mlx.win_y_size = 720;
}

void	init_mlx(t_data *p)
{
	init_mlx_params(p);
	if(!(p->mlx.mlx = mlx_init()))
		error(-13);
	if(!(p->mlx.win = mlx_new_window(p->mlx.mlx, p->mlx.win_x_size, p->mlx.win_y_size, "wolf3d")))
		error(-13);
	if(!(p->mlx.img = mlx_new_image(p->mlx.mlx, p->mlx.win_x_size, p->mlx.win_y_size)))
		error(-13);
	if(!(p->mlx.img_data = (int *)mlx_get_data_addr(p->mlx.img, &p->mlx.bit_per_pixel, &p->mlx.size_line
	, &p->mlx.endline)))
		error(-13);
}

