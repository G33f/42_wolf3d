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

#include "../header/wolf3d.h"

int		y_size(char *set/*, t_data *p*/)
{
	int		fd;
	int		i;
	char	*line;
//	int		r;

	i = 0;
	fd = open(set, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
//		r = ft_strlen(line);
//		ft_putnbr(ft_strlen(line));
//		ft_putstr("\n");
//		ft_putstr(line);
//		ft_putchar('\n');
		free(line);
//		if (r != p->map.x_size)
//			error(-13);
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
		ft_putstr(line);
		ft_putchar('\n');
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
	p->map.y_size = y_size(set);
	if (!(p->map.map = malloc(sizeof(char *) * p->map.y_size)))
		error(-12);
	fd = open(set, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		p->map.map[i++] = line;
	}
	p->map.map[i] = NULL;
	close(fd);
}
