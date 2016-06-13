/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 03:35:54 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/13 18:55:24 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				asm_check_command(int x, char **array, t_strct *strct)
{
	if (x < 0 || array == NULL || strct == NULL)
		return (1);
	return (1);
}

int				asm_is_command(char **array, t_strct *strct)
{
	int x;

	x = 0;
	while (strct->tab_command[x])
	{
		if (!ft_strcmp(array[0], strct->tab_command[x]))
		{
			if (asm_check_command(x, array, strct) == 0)
				return (1);
			else
				asm_error("Erreur, moi pas comprendre!");
		}
		x++;
	}
	return (0);
}

int				asm_is_label(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == LABEL_CHAR)
		{
			if (str[i + 1])
				return (0);
			return (1);
		}
		if (ft_strchr(LABEL_CHARS, str[i]) == NULL)
			return (0);
		i++;
	}
	return (0);
}

void			asm_save_label(char *str, t_strct *strct)
{
	t_byteline *ptr;

	if (strct->bytelines == NULL)
	{
		if ((strct->bytelines = (t_byteline*)malloc(sizeof(t_byteline))) == NULL)
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
	ptr->next = NULL;
	ptr->label = 1;
	ptr->name = ft_strdup(str);
}

t_str			*asm_check_label(t_str *lst, t_strct *strct)
{
	char	**array;

	array = ft_strsplit(lst->str + strct->c, ' ');
	if (asm_is_label(array[0]) == 0)
	{
		if (asm_is_command(array, strct) == 0)
			return (NULL);
	}
	else
	{
		asm_save_label(array[0], strct);
		strct->c += ft_strlen(array[0]) + 1;
		free(array);
		array = ft_strsplit(lst->str + strct->c, ' ');
		if (!array[0] || array[0][0] == '#')
		{
		}
		else if (asm_is_command(array, strct) == 0)
			return (NULL);
	}
	return (lst->next);
}
