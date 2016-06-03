/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 19:33:54 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 16:25:52 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		parse_lmod(t_info *info)
{
	char *lmod;

	lmod = "lhjz";
	if (info->format[info->cursor] == 'l' &&
			info->format[info->cursor + 1] == 'l')
		info->lmod->ll = 1;
	else if (info->format[info->cursor] == 'l')
		info->lmod->l = 1;
	else if (info->format[info->cursor] == 'h' &&
				info->format[info->cursor + 1] == 'h')
		info->lmod->hh = 1;
	else if (info->format[info->cursor] == 'h')
		info->lmod->h = 1;
	else if (info->format[info->cursor] == 'j')
		info->lmod->j = 1;
	else if (info->format[info->cursor] == 'z')
		info->lmod->z = 1;
	if (ft_strchr(lmod, info->format[info->cursor]))
		info->cursor++;
}

static void		parse_prec(t_info *info)
{
	if (info->format[info->cursor] == '.')
	{
		info->isprec = TRUE;
		info->prec = 0;
		info->cursor++;
		extract_nb_from_str(info, &info->prec);
	}
}

static void		parse_field(t_info *info)
{
	if (info->format[info->cursor] != '0' &&
			ft_isdigit(info->format[info->cursor]))
		extract_nb_from_str(info, &info->field);
}

static void		parse_flags(t_info *info)
{
	char *flags;

	flags = "0#+- ";
	if (info->format[info->cursor] == '0')
		info->flag->zero = 1;
	else if (info->format[info->cursor] == '#')
		info->flag->sharp = 1;
	else if (info->format[info->cursor] == '+')
		info->flag->plus = 1;
	else if (info->format[info->cursor] == '-')
		info->flag->minus = 1;
	else if (info->format[info->cursor] == 32)
		info->flag->space = 1;
	if (ft_strchr(flags, info->format[info->cursor]))
		info->cursor++;
}

void			build_info(t_info *info, va_list ap)
{
	char *ptr;

	info->cursor++;
	while (info->format[info->cursor] != '\0' &&
				ft_strchr(OPTIONS, info->format[info->cursor]))
	{
		parse_flags(info);
		parse_field(info);
		parse_prec(info);
		parse_lmod(info);
	}
	if (info->format[info->cursor] && (ptr = ft_strchr(CONVERSIONS,
							info->format[info->cursor])) && info->cursor++)
	{
		info->c = *ptr;
		conv_arg(info->c, info, ap);
	}
	else if (info->format[info->cursor])
	{
		info->tmp = ft_strjoin_free(info->tmp,
					ft_charstr(info->format[info->cursor++]));
		transform_str(info, info->tmp);
	}
}
