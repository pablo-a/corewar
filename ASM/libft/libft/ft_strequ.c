/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:52:30 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/15 00:26:15 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strequ(char const *s1, char const *s2)
{
	ssize_t ret;

	ret = -1;
	if (s1 && s2)
		ret = ft_strcmp(s1, s2);
	if (ret == 0)
		return (1);
	else
		return (0);
}
