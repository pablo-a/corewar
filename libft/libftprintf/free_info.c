/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:07:46 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 16:08:08 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	free_info(t_info *info)
{
	if (info && info->flag)
		ft_memdel((void**)&(info->flag));
	if (info && info->lmod)
		ft_memdel((void**)&(info->lmod));
	if (info)
		ft_memdel((void**)&info);
}
