/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <hgreenfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 21:43:50 by hgreenfe          #+#    #+#             */
/*   Updated: 2020/03/15 15:46:13 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"
#include "reader.h"

t_map	*load_map_from_file(char const *filename)
{
	t_map	*map;
	int		fd;
	int		int_buf;

	fd = open(filename, O_RDONLY);
	if (!fd)
		return (NULL);
	map = ft_memalloc(sizeof(t_map));
	int_buf = 0;
	if (read_buffer(fd, sizeof(char), &int_buf) == NO_ERR)
	{
		if (mapreader(fd, map, int_buf) != NO_ERR)
		{
			ft_putendl_fd("ERROR!\tmap reading error!", FD_ERR);
			ft_memdel((void**)&map);
		}
	}
	close(fd);
	if (map && map->size_x > 0 && map->size_y > 0)
		return (map);
	ft_putendl_fd("ERROR!\tmap reading error!", FD_ERR);
	ft_memdel((void**)&map);
	return (NULL);
}
