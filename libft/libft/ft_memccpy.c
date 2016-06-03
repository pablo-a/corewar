/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:31:49 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/14 15:20:57 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, void const *src, ssize_t c, size_t n)
{
	unsigned char	*tmpd;
	unsigned char	*tmps;

	tmpd = (unsigned char *)dst;
	tmps = (unsigned char *)src;
	while (n--)
	{
		*tmpd = *tmps;
		if (*tmps == (unsigned char)c)
			return (tmpd + 1);
		tmpd++;
		tmps++;
	}
	return (NULL);
}
