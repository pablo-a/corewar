/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:43:05 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/15 00:27:24 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strnequ(char const *s1, char const *s2, size_t n)
{
	ssize_t ret;

	ret = -1;
	if (s1 && s2)
		ret = ft_strncmp(s1, s2, n);
	if (ret == 0)
		return (1);
	else
		return (0);
}
