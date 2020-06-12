/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:28:01 by wpoudre           #+#    #+#             */
/*   Updated: 2020/06/10 14:59:52 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf3d.h"

void	draw(t_data *p, int i, int column_h)
{
	int	space;
	int r;

	r = 0;
	space = (p->mlx.win_y_size - column_h) / 2;
	while(r < column_h && (r + 1 + space) < p->mlx.win_y_size)
	{
		p->mlx.img_data[i + (r + space) * p->mlx.win_x_size] = 0xFFFFFF;
		r++;
	}
}

void	casting(t_data *p, float angel, int i)
{
/*	float	t;
	ray		r;
	float	cameraX;
	int		column_h;

	t = 0;
	while(t++ < p->mlx.win_x_size)
	{
		cameraX =
	}
	cx = p->ply.x + t * cos(angel);
	cy = p->ply.y + t * sin(angel);
	if (p->map.map[(int)cx][(int)cy] != '0')
		column_h = p->mlx.win_y_size/(t * cos(angel - p->ply.a));
	draw(p, i, column_h);*/
}

void	render(t_data *p)
{
	int r;
	int dof;
	float aTan;
	float angel;

	r = 0;
	angel = p->ply.a;
	while(r++ < 1)
	{
		dof = 0;
		aTan = -1/tan(angel);
		if (angel < ME_PE)
	}

/*	float	angle;
	int	i;

	i = 0;
	while (i++ < p->mlx.win_x_size)
	{
		angle = p->ply.a - p->ply.fov / 2 + p->ply.fov * i / (float)p->mlx.win_x_size;
		casting(p, angle, i);
		i++;
	}*/
}

void	map_render(t_data *p)
{
	double posX = 22, posY = 12;  //x and y start position
	double dirX = -1, dirY = 0; //initial direction vector
	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame

	int x;
	for(x = 0; x < p->mlx.win_x_size; x++)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)p->mlx.win_x_size - 1; //x-coordinate in camera space
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;
		//which box of the map we're in
		int mapX = int(posX);
		int mapY = int(posY);

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = abs(1 / rayDirX);
		double deltaDistY = abs(1 / rayDirY);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if(p->map.map[mapX][mapY] != '0') hit = 1;
		}
		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if(side == 0) perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		else          perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(h / perpWallDist);
		draw(p, x, LineHeight);
}