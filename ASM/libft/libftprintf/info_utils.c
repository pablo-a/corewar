/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:28:04 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 15:28:40 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_info	*lmod_init(t_info *info)
{
	info->lmod->h = FALSE;
	info->lmod->hh = FALSE;
	info->lmod->l = FALSE;
	info->lmod->ll = FALSE;
	info->lmod->j = FALSE;
	info->lmod->z = FALSE;
	return (info);
}

static t_info	*flag_init(t_info *info)
{
	info->flag->sharp = FALSE;
	info->flag->zero = FALSE;
	info->flag->plus = FALSE;
	info->flag->minus = FALSE;
	info->flag->space = FALSE;
	return (info);
}

static t_info	*info_init(t_info *info)
{
	info->c = '\0';
	info->prec = 0;
	info->isprec = FALSE;
	info->field = 0;
	info->tmp = NULL;
	info->oct = 0;
	info->oct2 = 0;
	return (info);
}

static t_info	*info_alloc(t_info *info, char *format)
{
	if (!info)
	{
		info = (t_info*)malloc(sizeof(t_info));
		if (!info)
			return (NULL);
		info->flag = (t_flag*)malloc(sizeof(t_flag));
		info->lmod = (t_lmod*)malloc(sizeof(t_lmod));
		if (!(info->flag) || !(info->lmod))
			return (NULL);
		info->format = format;
		info->cursor = 0;
		info->str = NULL;
		info->ret = 0;
	}
	return (info);
}

t_info			*info_utils(t_info *info, char *format)
{
	if (!info && *format)
	{
		info = info_alloc(info, format);
	}
	else if (info)
	{
		info = info_init(info);
		info = flag_init(info);
		info = lmod_init(info);
	}
	return (info);
}
