/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:05:48 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/14 15:13:35 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_strlcat(char *dst, char const *src, size_t size)
{
	ssize_t		tmp;
	size_t		sumlen;

	sumlen = ft_strlen(dst) + ft_strlen(src);
	if (ft_strlen(dst) > size)
		return (size + ft_strlen(src));
	else
		tmp = size - ft_strlen(dst) - 1;
	while (*dst)
		dst++;
	while (*src && tmp-- > 0)
		*dst++ = *src++;
	*dst = '\0';
	return (sumlen);
}
