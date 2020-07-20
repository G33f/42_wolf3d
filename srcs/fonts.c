/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <hgreenfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:01:26 by hgreenfe          #+#    #+#             */
/*   Updated: 2020/06/14 21:54:13 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"

void	set_transparent(t_font *font)
{
	int		i;

	i = 0;
	while (i < font->full_h * font->full_w)
	{
		font->pixels[i] = (font->pixels[i] == font->transparent_color)
			? 0x00000000u
			: font->pixels[i];
		++i;
	}
}

t_font	*load_font(char *filename, int rows_count, int cols_count)
{
	SDL_Surface		*bmp;
	t_font			*font;

	bmp = SDL_LoadBMP(filename);
	if (!bmp)
		return (NULL);
	font = ft_memalloc(sizeof(t_font));
	font->full_w = bmp->w;
	font->full_h = bmp->h;
	font->rows_count = rows_count;
	font->cols_count = cols_count;
	font->letter_w = font->full_w / cols_count;
	font->letter_h = font->full_h / rows_count;
	font->pitch = bmp->pitch;
	font->transparent_color = (unsigned int)(((unsigned int*)bmp->pixels)[0]);
	font->pixels = ft_memalloc(bmp->pitch * bmp->h);
	font->pixels = ft_memcpy(font->pixels, bmp->pixels, bmp->pitch * bmp->h);
	set_transparent(font);
	SDL_FreeSurface(bmp);
	return (font);
}

void	free_font(t_font *pfont)
{
	if (!pfont)
		return ;
	ft_bzero(pfont->pixels,
		sizeof(unsigned int) * pfont->full_w * pfont->full_h);
	ft_memdel((void**)&(pfont->pixels));
	ft_bzero(pfont->array, sizeof(char) * MAX_LETTERS_COUNT);
	ft_memdel((void**)&(pfont->array));
	ft_memdel((void**)&pfont);
}

void	print_char(t_game *game, SDL_Point p, t_font *font, char ch)
{
	int				letter_in_font_col;
	int				letter_in_font_row;
	int				i;
	int				j;
	unsigned int	color;

	letter_in_font_row = font->array[(int)ch] / font->cols_count;
	letter_in_font_col = font->array[(int)ch] % font->cols_count;
	if (p.x + font->letter_w > game->rect->w || p.x < 0
	|| p.y + font->letter_h > game->rect->h || p.y < 0)
		return ;
	i = 0;
	while (i < font->letter_h)
	{
		j = 0;
		while (j < font->letter_w)
		{
			color = font->pixels[((letter_in_font_col * font->letter_w) + j) +
				((letter_in_font_row * font->letter_h) + i) * font->full_w];
			game->pixels[(p.x + j) + (p.y + i) * game->rect->w] |= color;
			++j;
		}
		++i;
	}
}

void	print_str(t_game *game, SDL_Point p, t_font *font, char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		print_char(game, p, font, str[i]);
		++i;
		p.x += font->letter_w;
	}
}
