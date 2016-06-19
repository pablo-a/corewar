/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 12:50:44 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/20 00:12:46 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int			asm_check_file(t_strct *strct)
{
	t_str		*ptr;

	ptr = strct->file;
	while (ptr)
	{
		strct->c = asm_str_browse(ptr->str);
		if (ptr->str[strct->c] == 0 || ptr->str[strct->c] == '#')
			ptr = ptr->next;
		else if (strct->name == NULL || strct->comment == NULL)
		{
			if (ptr->str[strct->c] != '.')
				asm_lc_error(strct);
			else if ((ptr = asm_check_header(ptr, strct)) == NULL)
				exit(0);
		}
		else if (ft_strchr(LABEL_CHARS, ptr->str[strct->c]) != NULL)
			ptr = asm_check_label(ptr, strct);
		else
			asm_lc_error(strct);
		strct->c = 0;
		strct->l += 1;
	}
	return (0);
}
