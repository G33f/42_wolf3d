/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:24:04 by hgreenfe          #+#    #+#             */
/*   Updated: 2018/11/25 01:48:45 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int		negative;

	negative = 1;
	if (n < 0)
	{
		negative = -1;
		ft_putchar('-');
	}
	if (n < 10 && n > -10)
	{
		ft_putchar('0' + n * negative);
		return ;
	}
	ft_putnbr((n / 10) * negative);
	ft_putchar((n % 10) * negative + '0');
}
