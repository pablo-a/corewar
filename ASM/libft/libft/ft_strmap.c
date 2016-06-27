/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:36:30 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/16 14:01:40 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmap(char const *s, char (*f)(char))
{
	char *ret;
	char *tmp;

	if (!s)
		return (NULL);
	ret = ft_strnew(ft_strlen(s));
	tmp = ret;
	if (tmp)
		while (*s)
		{
			if (f(*s))
				*tmp++ = f(*s++);
		}
	return (ret);
}
