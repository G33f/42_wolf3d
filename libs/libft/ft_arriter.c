/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arriter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <hgreenfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:58:31 by hgreenfe          #+#    #+#             */
/*   Updated: 2020/06/13 16:59:06 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arriter(char *s, size_t size, void (*f)(char *))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (i < size)
	{
		f(s + i);
		++i;
	}
}
