/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:30:47 by wpoudre           #+#    #+#             */
/*   Updated: 2020/06/10 14:51:48 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	kay_prass(int kay, t_data *p)
{
	if (kay == 123)
		p->ply.a += 0.30;
	if (kay == 124)
		p->ply.a -= 0.30;
	mlx_clear_window(p->mlx.mlx, p->mlx.win);
	img_rebild(p)
	render(p);
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
	render(&p);
	ft_putstr("2 - all right\n");
	mlx_hook(p.mlx.win , 2, 0, kay_prass, &p);
	mlx_put_image_to_window(p.mlx.mlx, p.mlx.win, p.mlx.img, 0, 0);
	mlx_loop(p.mlx.mlx);
	return (0);
}
