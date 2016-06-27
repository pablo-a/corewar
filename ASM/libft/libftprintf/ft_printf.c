/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 19:19:16 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 16:07:17 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_info	*parse_format(t_info *info, va_list ap)
{
	while (info->format[info->cursor])
	{
		if (info->format[info->cursor] == '%')
		{
			info = info_utils(info, NULL);
			build_info(info, ap);
		}
		else
		{
			while (info->format[info->cursor] &&
					info->format[info->cursor] != '%')
				info->str =
					ft_strjoin_free(info->str,
									ft_charstr(info->format[info->cursor++]));
		}
	}
	return (info);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_info		*info;
	int			ret;

	info = NULL;
	va_start(ap, format);
	info = info_utils(info, (char*)format);
	if (!ft_strlen(format))
		return (0);
	info = parse_format(info, ap);
	va_end(ap);
	print_buffer(info);
	ret = info->ret;
	free_info(info);
	return (ret);
}
