/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:30:31 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 16:32:28 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*cast(t_info *info, va_list ap)
{
	ssize_t	nb;

	if (info->lmod->z)
		nb = va_arg(ap, ssize_t);
	else if (info->lmod->j)
		nb = (intmax_t)va_arg(ap, ssize_t);
	else if (info->lmod->hh)
		nb = (char)va_arg(ap, ssize_t);
	else if (info->lmod->h)
		nb = (short)va_arg(ap, ssize_t);
	else
		nb = (int)va_arg(ap, ssize_t);
	return (ft_itoa(nb));
}

static char		*exception(t_info *info, char *str)
{
	char	*ret;

	ret = str;
	if (info->field && info->flag->zero)
	{
		if (*str == '-' || *str == '+' || *str == ' ')
		{
			info->str = ft_strjoin_free(info->str, ft_charstr(*str));
			ret = ft_strdup(str + 1);
			ft_strdel(&str);
			info->field--;
		}
	}
	return (ret);
}

void			conv_d(t_info *info, va_list ap)
{
	char	*str;

	if (info->lmod->l)
		conv_dd(info, ap);
	else
	{
		str = cast(info, ap);
		str = prec_nb(info, str);
		if (*str != '-' && !info->flag->plus && info->flag->space)
			str = ft_strjoin_free(ft_strdup(" "), str);
		if (*str != '-' && info->flag->plus)
			str = ft_strjoin_free(ft_strdup("+"), str);
		str = exception(info, str);
		transform_str(info, str);
	}
}
