/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:13:41 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 16:14:32 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t		cast(t_info *info, va_list ap)
{
	size_t	nb;

	if (info->lmod->z)
		nb = va_arg(ap, size_t);
	else if (info->lmod->j)
		nb = (uintmax_t)va_arg(ap, size_t);
	else if (info->lmod->hh)
		nb = (unsigned char)va_arg(ap, size_t);
	else if (info->lmod->h)
		nb = (unsigned short)va_arg(ap, size_t);
	else
		nb = (unsigned int)va_arg(ap, size_t);
	return (nb);
}

void				conv_o(t_info *info, va_list ap)
{
	char		*str;
	size_t		nb;

	if (info->lmod->l)
		conv_oo(info, ap);
	else
	{
		nb = cast(info, ap);
		str = ft_itoa_base_u(nb, 8, "01234567");
		str = prec_nb(info, str);
		if (info->flag->sharp && *str != '0')
			str = ft_strjoin_free(ft_strdup("0"), str);
		transform_str(info, str);
	}
}
