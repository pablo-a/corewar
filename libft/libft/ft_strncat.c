/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:02:23 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/15 00:52:18 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncat(char *s1, char const *s2, size_t n)
{
	char *save;

	save = s1;
	while (*save)
		save++;
	while (*s2 && n-- > 0)
		*save++ = *s2++;
	*save = '\0';
	return (s1);
}
