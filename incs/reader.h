/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:17:18 by hgreenfe          #+#    #+#             */
/*   Updated: 2020/06/24 17:17:21 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# ifdef WIN32
#  define _CRT_SECURE_NO_WARNINGS
#  include <stdio.h>
#  include <io.h>
#  define open _open
#  define read _read
#  define close _close
# else
#  include <unistd.h>
# endif
# include <fcntl.h>
# define	ACTUAL_VERSION	1

int		read_buffer(int fd, size_t size, void *ret);
int		mapreader(int fd, t_map *map, int version);
#endif
