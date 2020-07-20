/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:14:14 by hgreenfe          #+#    #+#             */
/*   Updated: 2018/11/23 22:29:53 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef WIN32
# include <io.h>
# define WRITE _write
#else
# include <unistd.h>
# define WRITE write
#endif
#include "libft.h"

void	ft_putstr(char const *s)
{
	if (s)
		WRITE(1, s, ft_strlen(s));
}
