/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:24:05 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/16 10:04:49 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *dst, char const *src)
{
	char *str;

	str = ft_strncpy(dst, src, ft_strlen(src));
	str[ft_strlen(src)] = '\0';
	return (str);
}
