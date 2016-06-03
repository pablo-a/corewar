/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:12:55 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 16:13:13 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		conv_p(t_info *info, va_list ap)
{
	size_t	arg;
	char	*str;

	arg = va_arg(ap, size_t);
	str = ft_itoa_base(arg, 16, BASE_MIN);
	str = prec_nb(info, str);
	if (info->field >= 2 && info->flag->zero)
	{
		info->str = ft_strjoin_free(info->str, ft_strdup("0x"));
		info->field = info->field - 2;
	}
	else
		str = ft_strjoin_free(ft_strdup("0x"), str);
	transform_str(info, str);
}
