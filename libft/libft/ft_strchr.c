/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:27:39 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 15:12:10 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *s, ssize_t c)
{
	char	*ts;

	ts = (char *)s;
	while (c && *ts)
	{
		if (*ts == c)
			return (ts);
		ts++;
	}
	return (NULL);
}
