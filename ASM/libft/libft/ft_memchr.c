/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:45:05 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/06 02:01:15 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(void const *s, ssize_t c, size_t n)
{
	unsigned char	*tmps;

	tmps = (unsigned char*)s;
	while (n > 0)
	{
		if (*tmps == (unsigned char)c)
			return (tmps);
		tmps++;
		n--;
	}
	return (NULL);
}
