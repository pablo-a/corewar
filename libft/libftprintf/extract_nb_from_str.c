/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_nb_from_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:08:24 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 16:08:42 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		extract_nb_from_str(t_info *info, size_t *save)
{
	size_t		i;
	size_t		j;
	char		*str;

	i = 0;
	j = 0;
	while (ft_isdigit(info->format[info->cursor]))
	{
		info->cursor++;
		i++;
	}
	if (i > 0)
	{
		str = ft_strnew((size_t)i);
		while (i > 0)
			str[--i] = info->format[info->cursor - ++j];
		*save = (size_t)ft_atoi(str);
		ft_strdel(&str);
	}
}
