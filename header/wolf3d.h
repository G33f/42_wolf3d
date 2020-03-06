/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:53:47 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/06 11:53:50 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H

#define WOLF3D_H

#include "libft.h"

typedef struct	s_map
{
	char		**map;
	int			x_size;
	int			y_size;
}				t_map;

typedef struct	s_data
{
	t_map		map;
}				t_data;

////reader----------------------------------------
void			map_reader(char *set, t_data *p);
int				x_size(char *set);
int				y_size(char *set/*, t_data *p*/);
////error-----------------------------------------
void			usage(int cod);
void			error(int cod);
void			error_log(int cod);

#endif