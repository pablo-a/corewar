/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_command_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 18:58:49 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/17 21:27:23 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void asm_check_and_or(char **array, t_strct *strct, t_byteline *new, int len)
{
    int c;
    int d;
    int kop1;

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
        asm_save_arg_finish(array[2] + d,array[3], strct, new->name, &len, c);
    new->len += 2;
}

void asm_check_ldi(char **array, t_strct *strct, t_byteline *new, int len)
{
	int c;
    int d;
    int kop1;

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
        asm_save_arg_finish(array[2] + d,array[3], strct, new->name, &len, c);
    new->len += 2;
}

void  asm_check_sti(char **array, t_strct *strct, t_byteline *new, int len)
{
	int c;
	int d;
	int kop1;

	kop1 = 0; // kop1 il aime pas segfault
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

void asm_check_aff(char **array, t_strct *strct, t_byteline *new, int len)
{
    int c;

    if (!array[0])
        asm_lc_error(strct);
    if (!(c = asm_is_reg(array[0], new)))
        asm_lc_error(strct);
    else
        asm_save_arg_finish(array[0], array[1], strct, new->name, &len, c);
    new->len += 2;
}

void             asm_save_command(t_byteline *new, t_strct *strct);

int asm_check_command(int i, char *str, t_strct *strct)//char **tab)
{
	t_byteline  *new;
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
		asm_check_live(array, strct, new, len);
		if (str[strct->c] == SEPARATOR_CHAR)
            asm_lc_error(strct);
        ret = 0;
	}
	else if (i == 8 || i == 11 || i == 14)
	{
		asm_check_zjmp_fork(array, strct, new, len);
		if (str[strct->c] == SEPARATOR_CHAR)
            asm_lc_error(strct);
        ret = 0;
	}
	else if (i == 1 || i == 12)
	{
		asm_check_ld(array, strct, new, len);
		if (str[strct->c] == SEPARATOR_CHAR)
			asm_lc_error(strct);
        ret = 0;
	}
	else if (i == 2)
	{
		asm_check_st(array, strct, new, len);
		if (str[strct->c] == SEPARATOR_CHAR)
            asm_lc_error(strct);
        ret = 0;
	}
	else if (i == 3 || i == 4)
    {
        asm_check_add_sub(array, strct, new, len);
        if (str[strct->c] == SEPARATOR_CHAR)
            asm_lc_error(strct);
        ret = 0;
    }
	else if (i > 4 && i < 8)
    {
        asm_check_and_or(array, strct, new, len);
        if (str[strct->c] == SEPARATOR_CHAR)
            asm_lc_error(strct);
        ret = 0;
    }
	else if (i == 9 || i == 13)
    {
        asm_check_ldi(array, strct, new, len);
        if (str[strct->c] == SEPARATOR_CHAR)
            asm_lc_error(strct);
        ret = 0;
    }
	else if (i == 10)
	{
		asm_check_sti(array, strct, new, len);
		if (str[strct->c] == SEPARATOR_CHAR)
			asm_lc_error(strct);
		ret = 0;
	}
	else if (i == 15)
	{
		asm_check_aff(array, strct, new, len);
		if (str[strct->c] == SEPARATOR_CHAR)
			asm_lc_error(strct);
		ret = 0;
	}
	else
	{
		int j = 0;
		while (array[j])
		{
			printf("{%s}\n", array[j]);
			j++;
		}

		exit(0);
	}
	if (ret == 0)
		asm_save_command(new, strct);
//	printf("\033[32m[%s]\n\033[37m", new->name);
	return (ret);
}

void             asm_save_command(t_byteline *new, t_strct *strct)
{
    t_byteline *ptr;

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
