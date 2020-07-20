/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 22:43:32 by hgreenfe          #+#    #+#             */
/*   Updated: 2018/11/24 05:38:35 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifdef WIN32
# define INC_PTR(x)  x = ((char*)x + 1)
#else
# define INC_PTR(x)  x++
#endif

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*start;

	start = (char*)dst;
	while (n--)
	{
		*(unsigned char*)dst = *(unsigned char*)src;
		INC_PTR(dst);
		INC_PTR(src);
	}
	return (start);
}
