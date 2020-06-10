/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:30:47 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/05 20:30:55 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "../minilibx/mlx.h"

int main(int argc, char **argv)
{
	t_data	p;

	if (argc != 2)
		error(-10);
	map_reader(argv[1], &p);
	init_params(&p);
	render(&p);
	mlx_put_image_to_window(p.mlx.mlx, p.mlx.win, p.mlx.img, 0, 0);
	mlx_loop(p.mlx.mlx);
	return (0);
}
