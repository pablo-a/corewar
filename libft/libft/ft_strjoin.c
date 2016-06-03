/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:30:42 by mcotfas           #+#    #+#             */
/*   Updated: 2016/03/08 15:55:56 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	char	*tmp;

	if (!s1 && !s2)
		return (ft_strnew(0));
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	tmp = ret;
	while (*s1 && tmp)
		*tmp++ = *s1++;
	while (*s2 && tmp)
		*tmp++ = *s2++;
	if (tmp)
		*tmp = '\0';
	return (ret);
}
