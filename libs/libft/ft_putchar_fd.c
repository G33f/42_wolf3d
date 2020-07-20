/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:13:28 by hgreenfe          #+#    #+#             */
/*   Updated: 2018/11/21 21:40:06 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE__
# include <unistd.h>
# define WRITE write
#else
# if WIN_32
#  define WRITE _write
#  include <io.h>
# else
#  include <sys/unistd.h>
#  define WRITE write
# endif
#endif

void	ft_putchar_fd(char c, int fd)
{
	WRITE(fd, &c, 1);
}
