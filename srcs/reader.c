/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:59:11 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/06 11:59:14 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		y_size(char *set, t_data *p)
{
	int		fd;
	int		i;
	char	*line;
	int		r;

	i = 0;
	fd = open(set, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		r = ft_strlen(line);
		free(line);
		if (r != p->map.x_size)
			error(-13);
		i++;
	}
	close(fd);
	return (i);
}

int		x_size(char *set)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(set, O_RDONLY, 0);
	if (get_next_line(fd, &line))
	{
		i = ft_strlen(line);
		free(line);
	}
	close(fd);
	return (i);
}

void	map_reader(char *set, t_data *p)
{
	int		fd;
	int		i;
	char	*line;

	p->map.x_size = x_size(set);
	p->map.y_size = y_size(set, p);
	if (!(p->map.map = malloc(sizeof(char *) * p->map.y_size)))
		error(-12);
	fd = open(set, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
		p->map.map[i++] = line;
	if (i != p->map.y_size)
	{
		ft_matdel((void**)p->map.map, i);
		exit(-12);
	}
	close(fd);
}
