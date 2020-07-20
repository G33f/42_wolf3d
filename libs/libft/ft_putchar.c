/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:13:28 by hgreenfe          #+#    #+#             */
/*   Updated: 2018/11/26 22:04:39 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE__
# include <unistd.h>
#else
# if __WIN32
#  include <io.h>
# else
#  include <sys/unistd.h>
# endif
#endif

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
