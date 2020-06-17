/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:17:06 by wpoudre           #+#    #+#             */
/*   Updated: 2020/06/12 16:48:10 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf3d.h"

void	init_player(t_data *p)
{
	p->ply.x = 2.0;
	p->ply.y = 4.0;
	p->ply.planeX = 0.0;
	p->ply.planeY = 0.66;
	p->ply.dirX = -1.0;
	p->ply.dirY = 0.0;
	p->ply.rotSpeed = 0.030 * 3;
	p->ply.moveSpeed = 0.030 * 5;
}

void	tex_mlc(t_textur *tex, int i)
{
	if(!(**tex->tex = malloc(sizeof(void *) * i)))
		error(-12);
	if(!(**tex->tex_data = malloc(sizeof(int *) * i)))
		error(-12);
	if(!(*tex->bit_per_pixel = malloc(sizeof(int) * i)))
		error(-12);
	if(!(*tex->size_line = malloc(sizeof(int) * i)))
		error(-12);
	if(!(*tex->endline = malloc(sizeof(int) * i)))
		error(-12);
	if(!(*tex->w = malloc(sizeof(int) * i)))
		error(-12);
	if(!(*tex->h = malloc(sizeof(int) * i)))
		error(-12);
}

void	init_params(t_data *p)
{
	init_mlx(p);
	init_player(p);
	textur_reader(&p->tex);
}
