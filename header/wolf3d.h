/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:53:47 by wpoudre           #+#    #+#             */
/*   Updated: 2020/06/11 23:13:02 by student          ###   ########.fr       */
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

typedef struct	s_textur
{
	void		**tex;
	int			**tex_data;
	int			*bit_per_pixel;
	int			*size_line;
	int			*endline;
	int			*w;
	int			*h;
}				t_textur;

typedef struct	s_ray
{
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	double		wall_x;
	int			mapX;
	int			mapY;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			tex_x;
	int			tex_nmb;
}				t_ray;

typedef struct	s_player
{
	double		x;
	double		y;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		moveSpeed;
	double		rotSpeed;
}				t_player;

typedef struct	s_data
{
	t_map		map;
	t_player	ply;
	t_mlx		mlx;
	t_textur	tex;
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
void			draw(t_data *p, int i, int column_h, t_ray *ray);
void			render_init(t_data *p, t_ray *ray, int x);
void			step_check(t_data *p, t_ray *ray);
void			casting(t_data *p, t_ray *ray);
void			map_render(t_data *p);
void			img_rebild(t_data *p);

#endif
