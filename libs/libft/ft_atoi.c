/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:26:46 by hgreenfe          #+#    #+#             */
/*   Updated: 2018/12/04 20:13:06 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_overlong(int neg, unsigned long num)
{
	if (neg > 0 && (num > 0x8000000000000000))
		return (0);
	if (neg < 0 && (num < 0x8000000000000000))
		return (-1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int			neg;
	long long	ret;

	neg = 1;
	ret = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\f' || *str == '\r')
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		++str;
	}
	while (ft_isdigit(*str) && !ft_is_overlong(neg, ret))
	{
		ret = 10 * ret + (*str - '0');
		++str;
	}
	if (ft_is_overlong(neg, (unsigned long)ret) > 0)
		return (-1);
	else if (ft_is_overlong(neg, (unsigned long)ret) < 0)
		return (0);
	return ((int)(ret * neg));
}
