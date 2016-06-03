/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:57:39 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 15:58:32 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	transform_char(t_info *info, size_t oct)
{
	char	*tmp;

	if (info->field != 0 && info->field > oct)
	{
		tmp = ft_strnew(info->field - oct);
		tmp = (char *)ft_memset(tmp, ' ', info->field - oct);
		if (info->flag->zero && !info->flag->minus)
			tmp = (char *)ft_memset(tmp, '0', info->field - oct);
		info->str = ft_strjoin_free(info->str, tmp);
		info->field = 0;
		info->flag->minus = 0;
	}
}
