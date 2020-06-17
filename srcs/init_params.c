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

t_textur	*get_textur(int i, t_data *p)
{
	t_textur *t;
	int r;

	t = &p->tex;
	r = 0;
	while (r < i)
	{
		t = t->next;
		r++;
	}
	return (t);
}

t_textur	new_tex()
{
	t_textur text;

	text.next = NULL;
	return (text);
}

void	init_params(t_data *p)
{
	init_mlx(p);
	init_player(p);
	p->tex.newt = NULL;
	textur_reader(&p->tex);
}
