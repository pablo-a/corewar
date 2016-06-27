/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 10:42:37 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/16 12:16:53 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstsplit(char const *s, char c)
{
	t_list			*lst;
	size_t			i;
	size_t			j;
	char			*tmp;

	i = 0;
	lst = NULL;
	if (!s)
		return (NULL);
	while (i < ft_strlen((char *)s))
	{
		j = 0;
		while (s[i + j] != c && s[i + j])
			j++;
		if (j > 0)
		{
			tmp = ft_strsub(s, i, j);
			lst = ft_lstaddend(lst, ft_lstnew(tmp, ft_strlen(tmp)));
		}
		i = i + j + 1;
	}
	return (lst);
}
