/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:15:59 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/09 13:05:43 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(char const *s1)
{
	char *dup;

	dup = ft_strnew(ft_strlen(s1));
	if (dup)
		return (ft_strcpy(dup, s1));
	return (NULL);
}
