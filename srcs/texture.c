/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <hgreenfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 21:16:18 by hgreenfe          #+#    #+#             */
/*   Updated: 2020/06/22 01:29:39 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"

int				get_wall_type(t_ray *ray, t_game *game)
{
	if (ray->side)
	{
		ray->wall_x = game->player->pos_x + ray->perp_wall_dist * ray->dir_x;
		if (ray->map_y > game->player->pos_y)
			return (NORTH_WALL);
		else
			return (SOUTH_WALL);
	}
	else
	{
		ray->wall_x = game->player->pos_y + ray->perp_wall_dist * ray->dir_y;
		if (ray->map_x > game->player->pos_x)
			return (EAST_WALL);
		else
			return (WEST_WALL);
	}
}

unsigned int	get_texture_pixel(t_texture *tex, numeric x,
	numeric y, numeric height)
{
	unsigned int	color;

	x = (x * TEX_REPEAT_COUNT * (numeric)tex->rect->w);
	x = ((int)x % (tex->rect->w));
	x += tex->rect->w * tex->num;
	y = ((int)((numeric)y * TEX_REPEAT_COUNT * (numeric)tex->rect->h /
		(numeric)height) % (tex->rect->h));
	color = 0xff000000u |
		tex->pixels[tex->bpp * ((int)x + (int)y * tex->width)] |
		tex->pixels[tex->bpp * ((int)x + (int)y * tex->width) + 1] << 8u |
		tex->pixels[tex->bpp * ((int)x + (int)y * tex->width) + 2] << 16u;
	return (color);
}

void			load_walls_texture(t_game *game, char *filename, int count)
{
	SDL_Surface		*surface;
	t_texture		*texture;

	surface = SDL_LoadBMP(filename);
	if (!surface)
		return ;
	texture = ft_memalloc(sizeof(t_texture));
	texture->width = surface->w;
	texture->height = surface->h;
	texture->pixels = ft_memalloc(surface->h * surface->pitch);
	texture->bpp = surface->pitch / surface->w;
	ft_memcpy(texture->pixels, surface->pixels, surface->h * surface->pitch);
	texture->rect = ft_memalloc(sizeof(SDL_Rect));
	texture->rect->w = surface->w / count;
	texture->rect->h = surface->h;
	texture->rect->x = 0;
	texture->rect->y = 0;
	texture->num = count;
	texture->enabled = 1;
	SDL_FreeSurface(surface);
	game->walls = texture;
}

void			free_walls_texture(t_game *game)
{
	if (!game->walls)
		return ;
	ft_memdel((void**)&(game->walls->pixels));
	ft_memdel((void**)&(game->walls->rect));
	ft_memdel((void**)&(game->walls));
}
