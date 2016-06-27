/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:10:21 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 16:10:53 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	cast(t_info *info, va_list ap)
{
	size_t nb;

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

void			conv_u(t_info *info, va_list ap)
{
	size_t	nb;
	char	*str;

	if (info->lmod->l)
		conv_uu(info, ap);
	else
	{
		nb = cast(info, ap);
		str = ft_itoa_base_u(nb, 10, "0123456789");
		str = prec_nb(info, str);
		transform_str(info, str);
	}
}
