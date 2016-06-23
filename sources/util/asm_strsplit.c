/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:34:44 by mcotfas           #+#    #+#             */
/*   Updated: 2016/06/23 23:58:42 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

char				**asm_initsplit(char const *s)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (i < ft_strlen((char *)s))
		while (s[i++] != ' ' && s[i - 1] != '\t'
			&& s[i - 1] != '\v' && s[i - 1])
			if (s[i] == ' ' || s[i] == '\t' || s[i] == '\0' || s[i] == '\v')
				j++;
	return ((char **)malloc(sizeof(char *) * (j + 1)));
}

char				**asm_strsplit(char const *s)
{
	size_t		i;
	size_t		j;
	char		**ret;
	int			k;

	ret = asm_initsplit(s);
	if (!ret)
		return (NULL);
	i = 0;
	k = 0;
	while (i < ft_strlen((char *)s))
	{
		j = 0;
		while (s[i + j] != ' ' && s[i + j] != '\t'
			&& s[i + j] != '\v' && s[i + j])
			j++;
		if (j > 0)
			ret[k++] = ft_strsub(s, i, j);
		i = i + j + 1;
	}
	ret[k] = NULL;
	return (ret);
}
