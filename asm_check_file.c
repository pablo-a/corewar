/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 12:50:44 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/12 01:03:36 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
int			asm_is_command(char *str)
{
	str = "";
	return (1);
}

int			asm_is_label(char *str)
{
	if (ft_strchr(str, LABEL_CHAR))
		return (1);
	return (0);
}
*/

int			asm_check_file(t_strct *strct)
{
	t_list		*ptr;
	int			c;

	ptr = strct->file;
	if ((c = asm_check_header(strct)) != 0)
		return (1);
/*	else if ((ptr = asm_check_label(ptr, strct)) < 0)
		return (1);
	else if ((ptr = asm_check_command(ptr, strct)) < 0)
	return (1); */
	// last_check;
	return (0);
}
