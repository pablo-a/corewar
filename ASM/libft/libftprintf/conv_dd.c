/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_dd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:27:36 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 16:27:53 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		conv_dd(t_info *info, va_list ap)
{
	ssize_t		nb;
	char		*str;

	if (info->lmod->ll)
		nb = (long long)va_arg(ap, ssize_t);
	else
		nb = (long)va_arg(ap, ssize_t);
	str = ft_itoa(nb);
	if (nb >= 0 && !info->flag->plus && info->flag->space)
		str = ft_strjoin_free(ft_strdup(" "), str);
	if (nb >= 0 && info->flag->plus)
		str = ft_strjoin_free(ft_strdup("+"), str);
	info->str = ft_strjoin_free(info->str, str);
}
