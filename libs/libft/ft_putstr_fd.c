/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:14:14 by hgreenfe          #+#    #+#             */
/*   Updated: 2018/11/22 20:36:04 by hgreenfe         ###   ########.fr       */
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

void	ft_putstr_fd(char const *s, int fd)
{
	if (s)
		WRITE(fd, s, ft_strlen(s));
}
