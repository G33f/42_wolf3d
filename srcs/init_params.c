/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:17:06 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/08 14:17:08 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf3d.h"

void	init_player(t_data *p)
{
	p->ply.x = 1.0;
	p->ply.y = 1.0;
	p->ply.a = 0.0;
	p->ply.fov = ME_PE/3;
}

void	init_params(t_data *p)
{
	init_mlx(p);
	init_player(p);
}
