/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 18:07:20 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/16 18:41:08 by vbarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
int asm_check_comment(char *str)
{
	if (str[0] == COMMENT_CHAR)
		return (1);
	return (0);
}
*/

void asm_check_live(char **array, t_strct *strct, t_byteline *new, int len)
{
	int c;

	if (!array[0])
        asm_lc_error(strct);
    if (!(c = asm_is_dir(array[0], new, 4)))
        asm_lc_error(strct);
    else
        asm_save_arg_finish(array[0], array[1], strct, new->name, &len, c);
	new->len += 1;
}

void asm_check_zjmp_fork(char **array, t_strct *strct, t_byteline *new, int len)
{
	int c;

	if (!array[0])
		asm_lc_error(strct);
	if (!(c = asm_is_dir(array[0], new, 2)))
		asm_lc_error(strct);
	else
		asm_save_arg_finish(array[0], array[1], strct, new->name, &len, c);
	new->len += 1;
}

void asm_check_ld(char **array, t_strct *strct, t_byteline *new, int len)
{
	int c;
	int d;
	int kop1;

	kop1 = 0;
	while (array[kop1])
		kop1++;
	if (kop1 < 2)
		asm_lc_error(strct);
	if (!(c = asm_is_dir(array[0], new, 4)) && !(c = asm_is_ind(array[0], new)))
		  asm_lc_error(strct);
	else
		asm_save_arg(array[0], strct, new->name, &len, c);
	d = asm_str_browse(array[1]);
    if (!(c = asm_is_reg(array[1] + d, new)))
		asm_lc_error(strct);
	else
		asm_save_arg_finish(array[1] + d,array[2], strct, new->name, &len, c);
    new->len += 2;
}

void asm_check_st(char **array, t_strct *strct, t_byteline *new, int len)
{
    int c;
    int d;
    int kop1;

    kop1 = 0;
    while (array[kop1])
        kop1++;
    if (kop1 < 2)
		asm_lc_error(strct);
	if (!(c = asm_is_reg(array[0], new)))
        asm_lc_error(strct);
	else
        asm_save_arg(array[0], strct, new->name, &len, c);
    d = asm_str_browse(array[1]);
    if (!(c = asm_is_ind(array[1] + d, new)) && !(c =asm_is_reg(array[1] + d, new)))
		asm_lc_error(strct);
    else
        asm_save_arg_finish(array[1] + d,array[2], strct, new->name, &len, c);
    new->len += 2;
}

void asm_check_add_sub(char **array, t_strct *strct, t_byteline *new, int len)
{
    int c;
    int d;
    int kop1;

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
    if (!(c = asm_is_reg(array[1] + d, new)))
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
