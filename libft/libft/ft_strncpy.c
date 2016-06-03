/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 20:05:06 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/15 00:06:17 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncpy(char *dst, char const *src, size_t n)
{
	char	*tmps;
	char	*tmpd;

	tmps = (char *)src;
	tmpd = dst;
	while (n > 0 && *tmps)
	{
		*tmpd++ = *tmps++;
		n--;
	}
	while (n-- > 0)
		*tmpd++ = '\0';
	return (dst);
}
