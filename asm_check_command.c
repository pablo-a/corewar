/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_command_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 18:58:49 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/18 21:07:24 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	asm_save_command(t_byteline *new, t_strct *strct)
{
	t_byteline	*ptr;

	if (strct->bytelines == NULL)
		strct->bytelines = new;
	else
	{
		ptr = strct->bytelines;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}

int		asm_check_command_3(char **array, int i, t_byteline *new, t_strct *strct, char *str)
{
	int ret;

	ret = 1;
	if (i == 9 || i == 13)
	{
		asm_ldi(array, strct, new);
		if (str[strct->c] == SEPARATOR_CHAR)
			asm_lc_error(strct);
		ret = 0;
	}
	else if (i == 10)
	{
		asm_sti(array, strct, new);
		if (str[strct->c] == SEPARATOR_CHAR)
			asm_lc_error(strct);
		ret = 0;
	}
	else if (i == 15)
	{
		asm_aff(array, strct, new);
		if (str[strct->c] == SEPARATOR_CHAR)
			asm_lc_error(strct);
		ret = 0;
	}
	else if (i == 8 || i == 11 || i == 14)
	{
		asm_zjmp(array, strct, new);
		if (str[strct->c] == SEPARATOR_CHAR)
			asm_lc_error(strct);
		ret = 0;
	}
	return (0);
}

int		asm_check_command_2(char **array, int i, t_byteline *new, t_strct *strct, char *str)
{
	int ret;

	ret = 1;
	if (i == 0)
	{
		asm_live(array, strct, new);
		if (str[strct->c] == SEPARATOR_CHAR)
			asm_lc_error(strct);
		ret = 0;
	}
	else if (i == 2)
	{
		asm_st(array, strct, new);
		if (str[strct->c] == SEPARATOR_CHAR)
			asm_lc_error(strct);
		ret = 0;
	}
	else if (i == 1 || i == 12)
	{
		asm_ld(array, strct, new);
		if (str[strct->c] == SEPARATOR_CHAR)
			asm_lc_error(strct);
		ret = 0;
	}
	else if (i == 3 || i == 4)
	{
		asm_add(array, strct, new);
		if (str[strct->c] == SEPARATOR_CHAR)
			asm_lc_error(strct);
		ret = 0;
	}
	else if (i > 4 && i < 8)
	{
		asm_and(array, strct, new);
		if (str[strct->c] == SEPARATOR_CHAR)
			asm_lc_error(strct);
		ret = 0;
	}
	return (0);
}

int		asm_check_command(int i, char *str, t_strct *strct)
{
	t_byteline	*new;
	int			ret;
	char		**array;

	ret = 1;
	new = (t_byteline*)malloc(sizeof(t_byteline));
	new->next = NULL;
	new->len = 0;
	new->label = 0;
	array = ft_strsplit(str + strct->c, ',');
	new->name = (char*)malloc(ft_strlen(str + strct->c) + 1);
	ft_bzero(new->name, ft_strlen(str + strct->c) + 1);
	ft_strcpy(new->name, strct->tab_command[i]);
	new->name_len = ft_strlen(strct->tab_command[i]);
	new->name[new->name_len] = ' ';
	new->name_len += 1;
	if (i < 8 || i == 12)
		ret = asm_check_command_2(array, i, new, strct, str);
	else if (i > 7)
		ret = asm_check_command_3(array, i, new, strct, str);
	else
		exit(0);
	new->label = 0;
	if (ret == 0)
		asm_save_command(new, strct);
	return (ret);
}
