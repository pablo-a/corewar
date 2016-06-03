/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:29:14 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 15:29:40 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*field(t_info *info, char *str)
{
	char *tmp;
	char *trans;

	tmp = ft_strnew(info->field - ft_strlen(str));
	tmp = (char*)ft_memset(tmp, ' ', info->field - ft_strlen(str));
	if (info->flag->minus)
		trans = ft_strjoin(str, tmp);
	else
	{
		if (info->flag->zero)
			tmp = (char*)ft_memset(tmp, '0', info->field - ft_strlen(str));
		trans = ft_strjoin(tmp, str);
	}
	info->field = 0;
	info->flag->minus = 0;
	ft_strdel(&str);
	ft_strdel(&tmp);
	return (trans);
}

void			transform_str(t_info *info, char *str)
{
	char *trans;

	if (info->field != 0 && info->field > ft_strlen(str))
	{
		trans = field(info, str);
	}
	else
		trans = str;
	info->str = ft_strjoin_free(info->str, trans);
}
