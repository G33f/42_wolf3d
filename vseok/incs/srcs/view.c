/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <hgreenfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:35:47 by hgreenfe          #+#    #+#             */
/*   Updated: 2020/03/11 20:39:39 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wolf3d.h"

int		main(int argc, char **argv)
{
	t_map	*map;
	int		i;
	int		j;

	if (argc == 2)
	{
		map = load_map_from_file(argv[1]);
		if (map && map->size_x * map->size_y > 0)
		{
			ft_putnbr(map->size_x);
			ft_putnbr(map->size_y);
			i = -1;
			while (++i < map->size_y)
			{
				j = -1;
				while (++j < map->size_x)
				{
					ft_putnbr(map->array[i * map->size_x + j]);
					ft_putchar(' ');
				}
				ft_putchar('\n');
			}
		}
	}
	return (0);
}
