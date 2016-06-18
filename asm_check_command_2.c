/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_command_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 18:58:49 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/18 17:50:32 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	asm_and(char **array, t_strct *strct, t_byteline *new, int len)
{
	int		c;
	int		d;
	int		kop1;

	kop1 = 0;
	while (array[kop1])
		kop1++;
	if (kop1 < 3)
		asm_lc_error(strct);
	if (!(c = asm_is_reg(array[0], new)) && !(c = asm_is_ind(array[0], new)) && !(c = asm_is_dir(array[0], new, 4)))
		asm_lc_error(strct);
	else
		asm_save_arg(array[0], strct, new->name, &len, c);
	d = asm_str_browse(array[1]);
	if (!(c = asm_is_reg(array[1] + d, new)) && !(c = asm_is_ind(array[1] + d, new)) && !(c = asm_is_dir(array[1] + d, new, 4)))
		asm_lc_error(strct);
	else
		asm_save_arg(array[1] + d, strct, new->name, &len, c);
	d = asm_str_browse(array[2]);
	if (!(c = asm_is_reg(array[2] + d, new)))
		asm_lc_error(strct);
	else
		asm_save_arg_finish(array[2] + d, array[3], strct, new->name, &len, c);
	new->len += 2;
}

void	asm_ldi(char **array, t_strct *strct, t_byteline *new, int len)
{
	int		c;
	int		d;
	int		kop1;

	kop1 = 0;
	while (array[kop1])
		kop1++;
	if (kop1 < 3)
		asm_lc_error(strct);
	if (!(c = asm_is_reg(array[0], new)) && !(c = asm_is_ind(array[0], new)) && !(c = asm_is_dir(array[0], new, 2)))
		asm_lc_error(strct);
	else
		asm_save_arg(array[0], strct, new->name, &len, c);
	d = asm_str_browse(array[1]);
	if (!(c = asm_is_reg(array[1] + d, new)) && !(c = asm_is_dir(array[1] + d, new, 2)))
		asm_lc_error(strct);
	else
		asm_save_arg(array[1] + d, strct, new->name, &len, c);
	d = asm_str_browse(array[2]);
	if (!(c = asm_is_reg(array[2] + d, new)))
		asm_lc_error(strct);
	else
		asm_save_arg_finish(array[2] + d, array[3], strct, new->name, &len, c);
	new->len += 2;
}

void	asm_sti(char **array, t_strct *strct, t_byteline *new, int len)
{
	int		c;
	int		d;
	int		kop1;

	kop1 = 0;
	while (array[kop1])
		kop1++;
	if (kop1 < 3)
		asm_lc_error(strct);
	if (!(c = asm_is_reg(array[0], new)))
		asm_lc_error(strct);
	else
		asm_save_arg(array[0], strct, new->name, &len, c);
	d = asm_str_browse(array[1]);
	if (!(c = asm_is_reg(array[1] + d, new)) && !(c = asm_is_dir(array[1] + d, new, 2))
		&& !(c = asm_is_ind(array[1] + d, new)))
	{
		asm_lc_error(strct);
	}
	else
		asm_save_arg(array[1] + d, strct, new->name, &len, c);
	d = asm_str_browse(array[2]);
	if (!(c = asm_is_reg(array[2] + d, new)) && !(c = asm_is_dir(array[2] + d, new, 2)))
		asm_lc_error(strct);
	else
		asm_save_arg_finish(array[2] + d,array[3], strct, new->name, &len, c);
	new->len += 2;
}

void	asm_aff(char **array, t_strct *strct, t_byteline *new, int len)
{
	int		c;

	if (!array[0])
		asm_lc_error(strct);
	if (!(c = asm_is_reg(array[0], new)))
		asm_lc_error(strct);
	else
		asm_save_arg_finish(array[0], array[1], strct, new->name, &len, c);
	new->len += 2;
}

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

int		asm_check_command(int i, char *str, t_strct *strct)//char **tab)
{
	t_byteline	*new;
	int			ret;
	char		**array;
	int			len;

	len = ft_strlen(str + strct->c);
	if (i == -1 || !str || !strct)
	{
		ft_putendl("Hello Gringo!!");
		exit(0);
	}
	ret = 1;
	new = (t_byteline*)malloc(sizeof(t_byteline));
	new->next = NULL;
	new->label = 0;
	new->len = 0;
	array = ft_strsplit(str + strct->c, ',');
	new->name = (char*)malloc(len + 1);
	ft_bzero(new->name, len + 1);
	ft_strcpy(new->name, strct->tab_command[i]);
	len = ft_strlen(strct->tab_command[i]);
	new->name[len] = ' ';
	len++;
	if (i == 0)
	{
		asm_live(array, strct, new, len);
		if (str[strct->c] == SEPARATOR_CHAR)
			asm_lc_error(strct);
		ret = 0;
	}
	else if (i == 8 || i == 11 || i == 14)
	{
		asm_zjmp(array, strct, new, len);
		if (str[strct->c] == SEPARATOR_CHAR)
			asm_lc_error(strct);
		ret = 0;
	}
	else if (i == 1 || i == 12)
	{
		asm_ld(array, strct, new, len);
		if (str[strct->c] == SEPARATOR_CHAR)
			asm_lc_error(strct);
		ret = 0;
	}
	else if (i == 2)
	{
		asm_st(array, strct, new, len);
		if (str[strct->c] == SEPARATOR_CHAR)
			asm_lc_error(strct);
		ret = 0;
	}
	else if (i == 3 || i == 4)
	{
		asm_add(array, strct, new, len);
		if (str[strct->c] == SEPARATOR_CHAR)
			asm_lc_error(strct);
		ret = 0;
	}
	else if (i > 4 && i < 8)
	{
		asm_and(array, strct, new, len);
		if (str[strct->c] == SEPARATOR_CHAR)
			asm_lc_error(strct);
		ret = 0;
	}
	else if (i == 9 || i == 13)
	{
		asm_ldi(array, strct, new, len);
		if (str[strct->c] == SEPARATOR_CHAR)
			asm_lc_error(strct);
		ret = 0;
	}
	else if (i == 10)
	{
		asm_sti(array, strct, new, len);
		if (str[strct->c] == SEPARATOR_CHAR)
			asm_lc_error(strct);
		ret = 0;
	}
	else if (i == 15)
	{
		asm_aff(array, strct, new, len);
	if (str[strct->c] == SEPARATOR_CHAR)
		asm_lc_error(strct);
	ret = 0;
	}
	else
	{
		exit(0);
	}
	if (ret == 0)
		asm_save_command(new, strct);
	return (ret);
}
