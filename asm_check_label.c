/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 03:35:54 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/18 20:35:43 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_is_command(t_str *lst, char **array, t_strct *strct)
{
	int x;

	x = 0;
	while (strct->tab_command[x])
	{
		if (!ft_strcmp(array[0], strct->tab_command[x]))
		{
			strct->c += ft_strlen(array[0]);
			if (lst->str[strct->c] != ' ' && lst->str[strct->c] != '\t')
				return (0);
			strct->c += asm_str_browse(lst->str + strct->c);
			if (asm_check_command(x, lst->str, strct) == 0)
				return (1);
			else
				asm_error("Erreur, moi pas comprendre!");
		}
		x++;
	}
	return (0);
}

int		asm_is_label(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == LABEL_CHAR)
			return (i);
		if (ft_strchr(LABEL_CHARS, str[i]) == NULL)
			return (0);
		i++;
	}
	return (0);
}

int		asm_save_label(char *str, t_strct *strct, int ret)
{
	t_byteline	*ptr;

	if (strct->bytelines == NULL)
	{
		if ((strct->bytelines =
			(t_byteline*)malloc(sizeof(t_byteline))) == NULL)
			asm_error("Malloc Fail");
		ptr = strct->bytelines;
	}
	else
	{
		ptr = strct->bytelines;
		while (ptr->next)
			ptr = ptr->next;
		if ((ptr->next = (t_byteline*)malloc(sizeof(t_byteline))) == NULL)
			asm_error("Malloc Fail");
		ptr = ptr->next;
	}
	str[ret] = 0;
	ptr->next = NULL;
	ptr->label = 1;
	ptr->name = ft_strdup(str);
	str[ret] = ':';
	return (ret);
}

t_str	*asm_check_label(t_str *lst, t_strct *strct)
{
	char	**array;
	int		ret;

	array = asm_strsplit(lst->str + strct->c);
	if ((ret = asm_is_label(array[0])) == 0)
	{
		if (asm_is_command(lst, array, strct) == 0)
			asm_error("EROOOOOR");
	}
	else
	{
		strct->c += asm_save_label(array[0], strct, ret) + 1;
		free(array);
		strct->c += asm_str_browse(lst->str + strct->c);
		if (!lst->str[strct->c] || lst->str[strct->c] == '#')
			return (lst->next);
		array = asm_strsplit(lst->str + strct->c);
		if (asm_is_command(lst, array, strct) == 0)
			asm_error("EROOOOOR");
	}
	free(array);
	return (lst->next);
}
