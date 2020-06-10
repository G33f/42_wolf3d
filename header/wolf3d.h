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

#define ME_PE	3.14159;

#include "libft.h"
#include "mlx.h"
#include <math.h>

typedef struct	s_mlx
{
	void		*win;
	void		*mlx;
	void		*img;
	int			win_x_size;
	int			win_y_size;
	int			bit_per_pixel;
	int			size_line;
	int			endline;
	int			*img_data;
}				t_mlx;

typedef struct	s_map
{
	char		**map;
	int			x_size;
	int			y_size;
}				t_map;

typedef struct	s_player
{
	float		x;
	float		y;
	float		a;
	float		fov;
}				t_player;

typedef struct	s_data
{
	t_map		map;
	t_player	ply;
	t_mlx		mlx;
}				t_data;

////init_params-----------------------------------
void			init_params(t_data *p);
void			init_mlx_params(t_data *p);
void			init_player(t_data *p);

////mlx_init--------------------------------------
void			init_mlx(t_data *p);

////reader----------------------------------------
void			map_reader(char *set, t_data *p);
int				x_size(char *set);
int				y_size(char *set, t_data *p);
////error-----------------------------------------
void			usage(int cod);
void			error(int cod);
void			error_log(int cod);

////render----------------------------------------
void			render(t_data *p);
void			casting(t_data *p, float angel, int i);
void			draw(t_data *p, int i, size_t column_h);

#endif