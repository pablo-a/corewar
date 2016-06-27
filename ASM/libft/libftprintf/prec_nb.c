/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_nb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:59:47 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 16:00:09 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*prec_nb(t_info *info, char *str)
{
	char	*tstr;
	int		i;

	i = 0;
	if (info->isprec && info->prec == 0 && *str == '0' && *(str + 1) == '\0')
		*str = '\0';
	else if (info->isprec)
	{
		info->flag->zero = 0;
		if (*str == '-')
			i++;
		tstr = ft_strdup(str + i);
		while (info->prec-- > ft_strlen(str) - i)
			tstr = ft_strjoin_free(ft_strdup("0"), tstr);
		if (*str == '-')
			tstr = ft_strjoin_free(ft_strdup("-"), tstr);
		ft_strdel(&str);
		str = tstr;
	}
	return (str);
}
