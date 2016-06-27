/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:07:14 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/09 12:02:20 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, void const *src, size_t n)
{
	char	*tmpd;
	char	*tmps;

	tmpd = (char*)dst;
	tmps = (char*)src;
	while (n--)
		*tmpd++ = *tmps++;
	return (dst);
}
