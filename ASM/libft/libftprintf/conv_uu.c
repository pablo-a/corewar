/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_uu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:11:59 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 16:12:22 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		conv_uu(t_info *info, va_list ap)
{
	size_t	nb;
	char	*str;

	if (info->lmod->ll)
		nb = (unsigned long long)va_arg(ap, size_t);
	else
		nb = (unsigned long)va_arg(ap, size_t);
	str = ft_itoa_base_u(nb, 10, "0123456789");
	str = prec_nb(info, str);
	transform_str(info, str);
}
