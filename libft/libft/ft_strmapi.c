/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:37:25 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/15 00:24:23 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(size_t, char))
{
	unsigned char	i;
	char			*ret;
	char			*tmp;

	ret = NULL;
	if (s)
		ret = ft_strnew(ft_strlen(s));
	i = 0;
	tmp = ret;
	if (s && tmp && f)
		while (*s)
			*tmp++ = (*f)(i++, *s++);
	return (ret);
}
