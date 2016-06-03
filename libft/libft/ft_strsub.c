/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:32:40 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/15 00:28:37 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strsub(char const *s, size_t start, size_t len)
{
	char *ret;
	char *tmp;

	ret = NULL;
	if (s && ft_strlen(s + start) >= len)
	{
		ret = ft_strnew(len);
		tmp = ret;
		while (len-- && ret)
			*tmp++ = *((s++) + start);
	}
	return (ret);
}
