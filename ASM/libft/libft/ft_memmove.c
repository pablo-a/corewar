/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 14:26:39 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/03 19:10:46 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, void const *src, size_t len)
{
	char	*tmps;
	char	*tmpd;

	tmps = (char*)src;
	tmpd = (char*)dst;
	if (tmpd > tmps)
	{
		tmpd = tmpd + len;
		tmps = tmps + len;
		while (len > 0)
		{
			*--tmpd = *--tmps;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*tmpd++ = *tmps++;
			len--;
		}
	}
	return (dst);
}
