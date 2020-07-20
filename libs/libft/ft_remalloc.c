/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:09:53 by hgreenfe          #+#    #+#             */
/*   Updated: 2018/12/01 08:20:44 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_remalloc(void *addr, size_t old_size, size_t new_size)
{
	char	*new;
	char	*old;

	old = addr;
	if (!addr || !new_size)
		return (NULL);
	new = malloc(new_size);
	if (!new)
		return (NULL);
	ft_memcpy(new, addr, old_size);
	ft_bzero(new + old_size, new_size - old_size);
	ft_memdel((void*)old);
	return (new);
}
