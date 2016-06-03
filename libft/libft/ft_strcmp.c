/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:59:44 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/04 22:25:16 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strcmp(char const *s1, char const *s2)
{
	if (ft_strlen(s1) > ft_strlen(s2))
		return (1);
	else if (ft_strlen(s1) < ft_strlen(s2))
		return (-1);
	else
		return (ft_memcmp(s1, s2, ft_strlen(s1)));
}
