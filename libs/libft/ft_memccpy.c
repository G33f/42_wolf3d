/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:19:32 by hgreenfe          #+#    #+#             */
/*   Updated: 2018/11/25 01:39:40 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifdef WIN32
# define INC_PTR(x)  (x++)
#else
# define INC_PTR(x)  x++
#endif

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n)
	{
		*((char*)INC_PTR(dst)) = *((char*)INC_PTR(src));
		if (*((unsigned char*)src - 1) == (unsigned char)c)
			break ;
		--n;
	}
	if (n)
		return (dst);
	else
		return (NULL);
}
