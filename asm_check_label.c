/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 03:35:54 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/13 18:01:34 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				asm_is_label(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == LABEL_CHAR)
			return (1);
		if (str[i] != LABEL_CHARS)
			return (0);
		i++;
	}
	return (0);
}

t_str			*asm_check_label(t_str *lst, t_strct *strct)
{
	char	**array;

	array = ft_strslipt(lst->str + strct->c);
	if (asm_is_label(array[0]) == 0)
	{
		if (asm_is_command(array[0]) == 0)
			return (NULL);
		else
			asm_save_command(array[0]);
	}
	else
		asm_save_label(array[0]);
	return (lst->next);
}

typedef struct s_byteline
{
	next;
	int		label; //(0 | 1)
	char	*name;
	int		index_tab_cmmand;
	char **parms,



	char	byte_cmd;
	char	byte_ocp;
	char	**byte_parms;
	int		size_line;

	// end
	char	*byte_line;
}
