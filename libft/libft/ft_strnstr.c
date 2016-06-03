/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:04:45 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/06 23:05:29 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	char	*tmps1;
	char	*tmps2;

	while (*s1 && n > 0)
	{
		i = 0;
		tmps1 = (char *)s1;
		tmps2 = (char *)s2;
		while (*tmps1 == *tmps2 && i < n && *tmps2)
		{
			i++;
			tmps1++;
			tmps2++;
		}
		if (i == ft_strlen(s2))
			return ((char *)s1);
		n--;
		s1++;
	}
	return (NULL);
}
