/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:36:45 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/04 23:10:56 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 1;
	while (s1[i - 1] && s2[i - 1])
		i++;
	if (i < n)
		n = i;
	return (ft_memcmp(s1, s2, n));
}
