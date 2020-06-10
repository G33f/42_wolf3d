/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:44:22 by wpoudre           #+#    #+#             */
/*   Updated: 2020/03/06 11:44:25 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	error_log(int cod)
{
	if (cod == 1)
		ft_putstr("low memory((\n");
	else if (cod == 2)
		ft_putstr("Incorect MAP");
	exit(0);
}

void	usage(int cod)
{
	if (cod == 1)
		ft_putstr("use map wit (*.rce)\n");
	else if (cod == 2)
		ft_putstr("use corect map wit (*.rce)\n");
	exit(0);
}

void	error(int cod)
{
	if (cod == -10)
		usage(1);
	else if (cod == -11)
		usage(2);
	else if (cod == -12)
		error_log(1);
	else if (cod == -13)
		error_log(2);
}
