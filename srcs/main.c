/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:30:47 by wpoudre           #+#    #+#             */
/*   Updated: 2020/06/11 23:16:55 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	rot(int i, t_data *p)
{
	double oldDirX;
	double oldPlane;

	oldDirX = p->ply.dirX;
	oldPlaneX = p->ply.planeX;
	if (i > 0)
	{
		p->ply.dirX = p->ply.dirX * cos(-p->ply.rotSpeed) - p->ply.dirY * sin(-p->ply.rotSpeed);
		p->ply.dirY = oldDirX * sin(-p->ply.rotSpeed) + p->ply.dirY * cos(-p->ply.rotSpeed);
		p->ply.planeX = p->ply.planeX * cos(-p->ply.rotSpeed) - p->ply.planeY * sin(-p->ply.rotSpeed);
		p->ply.planeY = oldPlaneX * sin(-p->ply.rotSpeed) + p->ply.planeY * cos(-p->ply.rotSpeed);
	}
	else
	{
		p->ply.dirX = p->ply.dirX * cos(p->ply.rotSpeed) - p->ply.dirY * sin(p->ply.rotSpeed);
		p->ply.dirY = oldDirX * sin(p->ply.rotSpeed) + p->ply.dirY * cos(p->ply.rotSpeed);
		p->ply.planeX = p->ply.planeX * cos(p->ply.rotSpeed) - p->ply.planeY * sin(p->ply.rotSpeed);
		p->ply.planeY = oldPlaneX * sin(p->ply.rotSpeed) + p->ply.planeY * cos(p->ply.rotSpeed);
	}
}

int	kay_prass(int kay, t_data *p)
{
	if (kay == 123)
		rot(1, p);
	if (kay == 124)
		rot(-1, p);
	mlx_clear_window(p->mlx.mlx, p->mlx.win);
	img_rebild(p);
	map_render(p);
	mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, p->mlx.img, 0, 0);
	return (kay);
}

int main(int argc, char **argv)
{
	t_data	p;

	if (argc != 2)
		error(-10);
	map_reader(argv[1], &p);
	ft_putstr("1 - all right\n");
	init_params(&p);
	map_render(&p);
	ft_putstr("2 - all right\n");
	mlx_hook(p.mlx.win , 2, 0, kay_prass, &p);
	mlx_put_image_to_window(p.mlx.mlx, p.mlx.win, p.mlx.img, 0, 0);
	mlx_loop(p.mlx.mlx);
	return (0);
}
