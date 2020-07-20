/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 22:38:59 by hgreenfe          #+#    #+#             */
/*   Updated: 2018/11/24 05:41:07 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifdef WIN32
# define INC_PTR(x)  x = ((char*)x + 1)
#else
# define INC_PTR(x)  x++
#endif

void	ft_bzero(void *s, size_t n)
{
	while (n--)
	{
		*(char*)s = (char)0;
		INC_PTR(s);
	}
}
