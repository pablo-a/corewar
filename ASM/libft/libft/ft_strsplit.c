/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:34:44 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/16 13:47:05 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char				**ft_initsplit(char const *s, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (i < ft_strlen((char *)s))
		while (s[i++] != c && s[i - 1])
			if (s[i] == c || s[i] == '\0')
				j++;
	return ((char **)malloc(sizeof(char *) * (j + 1)));
}

char				**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		j;
	char		**ret;
	int			k;
	char		*tmp;

	ret = ft_initsplit(s, c);
	if (!ret)
		return (NULL);
	i = 0;
	k = 0;
	while (i < ft_strlen((char *)s))
	{
		j = 0;
		while (s[i + j] != c && s[i + j])
			j++;
		if (j > 0)
		{
			tmp = ft_strsub(s, i, j);
			ret[k++] = tmp;
		}
		i = i + j + 1;
	}
	ret[k] = NULL;
	return (ret);
}
