/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:32:56 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 16:33:45 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_conv		*conv_init(void)
{
	t_conv	*conv;
	char	*convs;

	convs = CONVERSIONS;
	conv = (t_conv *)malloc(sizeof(*conv) * (ft_strlen(convs) + 1));
	conv[ft_strlen(convs)] = (t_conv){'\0', NULL};
	conv[0] = (t_conv){'s', conv_s};
	conv[1] = (t_conv){'d', conv_d};
	conv[2] = (t_conv){'p', conv_p};
	conv[3] = (t_conv){'i', conv_i};
	conv[4] = (t_conv){'c', conv_c};
	conv[5] = (t_conv){'x', conv_x};
	conv[6] = (t_conv){'o', conv_o};
	conv[7] = (t_conv){'u', conv_u};
	conv[8] = (t_conv){'D', conv_dd};
	conv[9] = (t_conv){'S', conv_ss};
	conv[10] = (t_conv){'X', conv_xx};
	conv[11] = (t_conv){'U', conv_uu};
	conv[12] = (t_conv){'O', conv_oo};
	conv[13] = (t_conv){'C', conv_cc};
	return (conv);
}

void				conv_arg(char c, t_info *info, va_list ap)
{
	t_conv	*conv;
	size_t	i;

	i = 0;
	conv = conv_init();
	while (conv[i].c != '\0')
	{
		if (conv[i].c == c)
			conv[i].f(info, ap);
		i++;
	}
	ft_memdel((void**)&conv);
}
