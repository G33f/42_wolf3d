/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 22:33:24 by hgreenfe          #+#    #+#             */
/*   Updated: 2018/11/23 20:34:17 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#ifdef WIN32
# define INC_PTR(x)  x = ((char*)x + 1)
#else
# define INC_PTR(x)  x++
#endif

void	*ft_memset(void *b, int c, size_t len)
{
	char	*start;

	start = b;
	c = (c & 0xff);
	while (len--)
	{
		*(char*)b = c & 0xff;
		INC_PTR(b);
	}
	return (start);
}
