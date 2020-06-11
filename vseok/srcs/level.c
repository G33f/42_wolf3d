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

#ifdef WIN32
# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <io.h>
# define open _open
# define read _read
# define close _close
#else
# include <unistd.h>
#endif
#include "wolf3d.h"
#include "libft.h"
#include <fcntl.h>
#define ACTUAL_VERSION 1

int		read_buffer(int fd, size_t size, void *ret)
{
	size_t	read_data_size;

	if (!ret)
		return (-1);
	read_data_size = read(fd, ret, size);
	return (read_data_size != size);
}

int		read_map_size(int fd, t_map *map)
{
	if (read_buffer(fd, sizeof(char), &(map->size_x)) != NO_ERR ||
		read_buffer(fd, sizeof(char), &(map->size_y)) != NO_ERR)
		return (SIZE_ERR);
	if (map->size_x * map->size_y <= 0)
	{
		ft_putendl_fd("ERROR!\tmap size is 0 or negative!", FD_ERR);
		return (SIZE_ERR);
	}
	map->array = ft_memalloc(sizeof(int) * map->size_x * map->size_y);
	if (!(map->array))
	{
		ft_putendl_fd("ERROR!\tmap memory is not allocated!", FD_ERR);
		return (MEM_ERR);
	}
	return (NO_ERR);
}

int		mapreader0(int fd, t_map *map)
{
	int		err;

	if ((err = read_map_size(fd, map)) != NO_ERR)
		return (err);
	if (read_buffer(fd,
		sizeof(char) * map->size_y * map->size_x, map->array) != NO_ERR)
		return (MAP_ERR);
	return (NO_ERR);
}

int		player_reader(int fd, t_map *map)
{
	int		buf_int;

	buf_int = 0;
	if (map)
	{
		if (read_buffer(fd, sizeof(int), &buf_int) != NO_ERR)
			return (VERSION_ERR);
		map->startpos = buf_int;
		buf_int = 0;
		if (read_buffer(fd, sizeof(int), &buf_int) != NO_ERR)
			return (VERSION_ERR);
		map->endpos = buf_int;
		if (map->startpos < 0 || map->startpos >= map->size_x * map->size_y
			|| map->endpos < 0 || map->endpos >= map->size_x * map->size_y)
			return (PLY_ERR);
		return (NO_ERR);
	}
	else
		return (MAP_ERR);
}

int		mapreader(int fd, t_map *map, int version)
{
	int		err;

	if (version == 0)
		return (mapreader0(fd, map));
	if (version == 1)
	{
		err = mapreader0(fd, map);
		err |= player_reader(fd, map);
		if (!err)
			map->version = version;
		return (err);
	}
	return (VERSION_ERR);
}

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
	return (map);
}
