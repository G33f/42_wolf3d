/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:30:47 by wpoudre           #+#    #+#             */
/*   Updated: 2020/06/12 17:20:48 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "../header/libft.h"

void	rot(int i, t_data *p)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = p->ply.dirX;
	oldPlaneX = p->ply.planeX;
	if (i < 0)
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

void move(int i, t_data *p)
{
	if (i > 0)
	{
		if(p->map.map[(int)(p->ply.x + p->ply.dirX * p->ply.moveSpeed)][(int)(p->ply.y)] == '0')
			p->ply.x += p->ply.dirX * p->ply.moveSpeed;
		if(p->map.map[(int)(p->ply.x)][(int)(p->ply.y + p->ply.dirY * p->ply.moveSpeed)] == '0')
			p->ply.y += p->ply.dirY * p->ply.moveSpeed;
	}
	else
	{
		if(p->map.map[(int)(p->ply.x - p->ply.dirX * p->ply.moveSpeed)][(int)(p->ply.y)] == '0')
			p->ply.x -= p->ply.dirX * p->ply.moveSpeed;
		if(p->map.map[(int)(p->ply.x)][(int)(p->ply.y - p->ply.dirY * p->ply.moveSpeed)] == '0')
			p->ply.y -= p->ply.dirY * p->ply.moveSpeed;
	}
}

int	kay_prass(int kay, t_data *p)
{
	if (kay == 123)
		rot(1, p);
	if (kay == 124)
		rot(-1, p);
	if (kay == 126)
		move(1, p);
	if(kay == 125)
		move(-1, p);
	mlx_clear_window(p->mlx.mlx, p->mlx.win);
	img_rebild(p);
	map_render(p);
	mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, p->mlx.img, 0, 0);
	return (kay);
}

void	textur_reader(t_data *p)
{
	char		**str;
	int			i;
	t_textur	*buf;
	t_textur	t;

	if(!(str = ft_strsplit("../textures/brick.xpm ../textures/grass.xpm "
				   "../textures/metal.xpm ../textures/stone.xpm ../textures/wood.xpm", ' ')));
		error(-12);
	i = 0;
	buf = &p->tex;
	while(str[i])
	{
		t = new_tex();
		t.tex = mlx_xpm_file_to_image(p.mlx.mlx, str[i], &t.w, &t.h);
		t.tex_data = (int *)mlx_get_data_addr(t.tex, &t.bit_per_pixel, &t.size_line, &t.endline);
		buf->next = &t;
		buf = &t;
	}
}

int main(int argc, char **argv)
{
	t_data		p;

	if (argc != 2)
		error(-10);
	map_reader(argv[1], &p);
	init_params(&p);
//	p.tex.tex = mlx_xpm_file_to_image(p.mlx.mlx, "../textures/brick.xpm", &p.tex.w, &p.tex.h);
//	p.tex.tex_data = (int *)mlx_get_data_addr(p.tex.tex, &p.tex.bit_per_pixel, &p.tex.size_line, &p.tex.endline);
	map_render(&p);
	mlx_hook(p.mlx.win , 2, 0, kay_prass, &p);
	mlx_put_image_to_window(p.mlx.mlx, p.mlx.win, p.mlx.img, 0, 0);
	mlx_loop(p.mlx.mlx);
	return (0);
}
