/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:34:14 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 16:34:28 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void		conv_c(t_info *info, va_list ap)
{
	char	arg;

	if (info->lmod->l)
		conv_cc(info, ap);
	else
	{
		if (!info->flag->minus)
			transform_char(info, 1);
		print_buffer(info);
		arg = va_arg(ap, unsigned int);
		write(1, &arg, 1);
		if (info->flag->minus)
			transform_char(info, 1);
		info->ret++;
	}
}
