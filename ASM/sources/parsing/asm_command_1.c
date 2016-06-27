/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 18:07:20 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/23 23:46:46 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void		asm_live(char **array, t_strct *strct, t_byteline *new)
{
	int			c;

	if (!array[0])
		asm_lc_error(strct);
	if (!(asm_is_dir(array[0], new, 4, &c)))
		asm_lc_error(strct);
	else
		asm_save_arg_finish(array, strct, new, c);
	new->len += 1;
}

void		asm_zjmp(char **array, t_strct *strct, t_byteline *new)
{
	int			c;

	if (!array[0])
		asm_lc_error(strct);
	if (!(asm_is_dir(array[0], new, 2, &c)))
		asm_lc_error(strct);
	else
		asm_save_arg_finish(array, strct, new, c);
	new->len += 1;
}

void		asm_ld(char **array, t_strct *strct, t_byteline *new)
{
	int			c;
	int			kop1;

	kop1 = 0;
	while (array[kop1])
		kop1++;
	if (kop1 < 2)
		asm_lc_error(strct);
	if (!(asm_is_dir(array[0], new, 4, &c)) && !(asm_is_ind(array[0], new, &c)))
		asm_lc_error(strct);
	else
		asm_save_arg(array[0], strct, new, c);
	new->label = asm_str_browse(array[1]);
	if (!(asm_is_reg(array[1] + new->label, new, &c)))
		asm_lc_error(strct);
	else
		asm_save_arg_finish(array + 1, strct, new, c);
	new->len += 2;
}

void		asm_st(char **array, t_strct *strct, t_byteline *new)
{
	int			c;
	int			kop1;

	kop1 = 0;
	while (array[kop1])
		kop1++;
	if (kop1 < 2)
		asm_lc_error(strct);
	if (!(asm_is_reg(array[0], new, &c)))
		asm_lc_error(strct);
	else
		asm_save_arg(array[0], strct, new, c);
	new->label = asm_str_browse(array[1]);
	if (!(asm_is_ind(array[1] + new->label, new, &c))
		&& !(asm_is_reg(array[1] + new->label, new, &c)))
		asm_lc_error(strct);
	else
		asm_save_arg_finish(array + 1, strct, new, c);
	new->len += 2;
}

void		asm_add(char **array, t_strct *strct, t_byteline *new)
{
	int			c;
	int			kop1;

	kop1 = 0;
	while (array[kop1])
		kop1++;
	if (kop1 < 3)
		asm_lc_error(strct);
	if (!(asm_is_reg(array[0], new, &c)))
		asm_lc_error(strct);
	else
		asm_save_arg(array[0], strct, new, c);
	new->label = asm_str_browse(array[1]);
	if (!(asm_is_reg(array[1] + new->label, new, &c)))
		asm_lc_error(strct);
	else
		asm_save_arg(array[1] + new->label, strct, new, c);
	new->label = asm_str_browse(array[2]);
	if (!(asm_is_reg(array[2] + new->label, new, &c)))
		asm_lc_error(strct);
	else
		asm_save_arg_finish(array + 2, strct, new, c);
	new->len += 2;
}
