/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:09:05 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 16:09:53 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*prec_str(t_info *info, char *str)
{
	char	*ret;
	size_t	i;

	if (info->isprec && info->prec < ft_strlen(str))
	{
		i = 0;
		ret = ft_strnew(info->prec);
		while (i < info->prec)
		{
			ret[i] = str[i];
			i++;
		}
		ft_strdel(&str);
		return (ret);
	}
	return (str);
}

void			conv_s(t_info *info, va_list ap)
{
	char	*s;
	char	*str;

	if (info->lmod->l)
		conv_ss(info, ap);
	else
	{
		s = va_arg(ap, char *);
		if (s == 0 && !info->isprec)
			str = ft_strdup("(null)");
		else if (s == 0)
			str = ft_strnew(0);
		else
		{
			str = ft_strdup(s);
			str = prec_str(info, str);
		}
		transform_str(info, str);
	}
}
