/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:12:56 by hgreenfe          #+#    #+#             */
/*   Updated: 2018/11/23 23:15:49 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ret;
	size_t	i;

	ret = malloc(size);
	if (ret)
	{
		i = 0;
		while (i < size)
		{
			((char*)ret)[i] = 0;
			++i;
		}
	}
	return (ret);
}
