/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:59:02 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 15:59:23 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		print_buffer(t_info *info)
{
	if (info->str)
	{
		ft_putstr(info->str);
		info->ret = info->ret + (int)ft_strlen(info->str);
		free(info->str);
		info->str = NULL;
	}
}
