/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:20:19 by hgreenfe          #+#    #+#             */
/*   Updated: 2018/11/24 22:59:27 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifdef WIN32
# define INC_PTR(x)  x = ((char*)x + 1)
#else
# define INC_PTR(x)  x++
#endif

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n)
	{
		if ((*(unsigned char*)s) == ((unsigned char)c))
			return ((void*)s);
		INC_PTR(s);
		--n;
	}
	return (NULL);
}
