/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <hgreenfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 17:01:00 by hgreenfe          #+#    #+#             */
/*   Updated: 2020/06/13 18:30:06 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_arrmap(char const *s, size_t size, char (*f)(char))
{
	size_t	i;
	char	*ret;

	if (!s || !f)
		return (NULL);
	ret = ft_memalloc(size);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ret[i] = f(s[i]);
		++i;
	}
	return (ret);
}
