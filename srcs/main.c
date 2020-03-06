/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:30:47 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/05 20:30:55 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf3d.h"

int main(int argc, char **argv)
{
	t_data	p;

	if (argc != 2)
		error(-10);
	map_reader(argv[1], &p);
	for (int i = 0; i < p.map.y_size; i++) {
		ft_putstr(p.map.map[i]);
		ft_putchar('\n');
	}
	return (0);
}
