/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <hgreenfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 18:27:30 by hgreenfe          #+#    #+#             */
/*   Updated: 2020/06/13 23:53:51 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

unsigned char	get_part_by_len(unsigned char max_bright,
	numeric length, numeric max_length)
{
	return (unsigned char)(max_bright / max_length * (max_length - length));
}

unsigned int	get_color_by_len(unsigned int max_bright,
	numeric length, numeric max_length)
{
	unsigned int	bright;

	if (length < max_length)
		bright = get_part_by_len(max_bright & 0xffu,
				length, max_length) |
			get_part_by_len((max_bright & 0xff00u) >> 8u,
					length, max_length) << 8u |
			get_part_by_len((max_bright & 0xff0000u) >> 16u,
					length, max_length) << 16u |
			get_part_by_len((max_bright & 0xff000000u) >> 24u,
					length, max_length) << 24u;
	else
		bright = 0;
	return (bright);
}

void			draw_line_by_y(unsigned int *pixels, SDL_Rect *view,
		SDL_Rect *line, unsigned int color)
{
	float	x;
	float	y;
	int		len_x;
	int		len_y;

	len_x = (line->w - line->x);
	len_y = (line->h - line->y);
	y = (float)line->y;
	x = (float)line->x;
	while (fabs(y - line->h) >= 1)
	{
		pixels[(int)x + (int)y * view->w] = color;
		x += len_x / (numeric)abs(len_y);
		y += len_y / fabs((numeric)len_y);
	}
}

void			draw_line_by_x(unsigned int *pixels, SDL_Rect *view,
		SDL_Rect *line, unsigned int color)
{
	float	x;
	float	y;
	int		len_x;
	int		len_y;

	len_x = (line->w - line->x);
	len_y = (line->h - line->y);
	y = (float)line->y;
	x = (float)line->x;
	while (fabs(x - line->w) >= 1)
	{
		pixels[(int)x + (int)y * view->w] = color;
		y += len_y / fabs((numeric)len_x);
		x += len_x / fabs((numeric)len_x);
	}
}

void			draw_line(unsigned int *pixels, SDL_Rect *view, SDL_Rect *line,
	unsigned int color)
{
	int		len_x;
	int		len_y;

	len_x = (line->w - line->x);
	len_y = (line->h - line->y);
	if (line->x > view->w || line->x < 0 || line->w < 0 || line->w > view->w
	|| line->y < 0 || line->y > view->h || line->h < 0 || line->h > view->h)
		return ;
	if (abs(len_y) > abs(len_x))
		draw_line_by_y(pixels, view, line, color);
	else
		draw_line_by_x(pixels, view, line, color);
}
