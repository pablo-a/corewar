/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:42:42 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/06 18:47:42 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, ssize_t c)
{
	char *tmps;

	tmps = (char *)s;
	while (*tmps)
		tmps++;
	if (c == '\0')
		return (tmps);
	while (tmps-- != (char *)s)
	{
		if (*tmps == c)
			return (tmps);
	}
	return (NULL);
}
