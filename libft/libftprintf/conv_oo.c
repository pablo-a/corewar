/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_oo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:26:26 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 16:26:51 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		conv_oo(t_info *info, va_list ap)
{
	size_t	nb;
	char	*str;

	if (info->lmod->ll)
		nb = (unsigned long long)va_arg(ap, ssize_t);
	else
		nb = (unsigned long)va_arg(ap, ssize_t);
	str = ft_itoa_base_u(nb, 8, "01234567");
	str = prec_nb(info, str);
	if (info->flag->sharp && *str != '0')
		str = ft_strjoin_free(ft_strdup("0"), str);
	transform_str(info, str);
}
