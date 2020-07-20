/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:28:45 by wpoudre           #+#    #+#             */
/*   Updated: 2020/06/25 16:28:48 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"

SDL_Point	set_to(int x, int y)
{
	SDL_Point	p;

	p.x = x;
	p.y = y;
	return (p);
}

void		fill_rect(unsigned int *pixels, SDL_Rect *view,
		SDL_Rect *rect, unsigned int color)
{
	int	x;
	int	y;

	y = 0;
	if (rect->x + rect->w > view->w || rect->x < 0
			|| rect->y + rect->h > view->h || rect->y < 0)
		return ;
	while (y < rect->h)
	{
		x = 0;
		while (x < rect->w)
		{
			pixels[rect->x + x + (rect->y + y) * view->w] = color;
			++x;
		}
		++y;
	}
}

SDL_Rect	create_rect(int x, int y, int w, int h)
{
	SDL_Rect	r;

	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	return (r);
}

int			set_array_font(t_font *font, char *array)
{
	int		i;

	i = 0;
	font->array = ft_memalloc(sizeof(char) * MAX_LETTERS_COUNT);
	ft_memset(font->array, 0xff, MAX_LETTERS_COUNT);
	while (i < font->rows_count * font->cols_count)
	{
		font->array[(int)array[i]] = (char)i;
		++i;
	}
	return (NO_ERR);
}
