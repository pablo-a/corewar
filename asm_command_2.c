/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_command_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 18:36:18 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/18 18:48:26 by hdebard          ###   ########.fr       */
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
	if (!(asm_is_reg(array[0], new, &c)) && !(asm_is_ind(array[0], new, &c))
		&& !(asm_is_dir(array[0], new, 4, &c)))
		asm_lc_error(strct);
	asm_save_arg(array[0], strct, new->name, &len, c);
	d = asm_str_browse(array[1]);
	if (!(asm_is_reg(array[1] + d, new, &c))
		&& !(asm_is_ind(array[1] + d, new, &c))
		&& !(asm_is_dir(array[1] + d, new, 4, &c)))
		asm_lc_error(strct);
	asm_save_arg(array[1] + d, strct, new->name, &len, c);
	d = asm_str_browse(array[2]);
	if (!(asm_is_reg(array[2] + d, new, &c)))
		asm_lc_error(strct);
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
	if (!(asm_is_reg(array[0], new, &c)) && !(asm_is_ind(array[0], new, &c))
		&& !(asm_is_dir(array[0], new, 2, &c)))
		asm_lc_error(strct);
	asm_save_arg(array[0], strct, new->name, &len, c);
	d = asm_str_browse(array[1]);
	if (!(asm_is_reg(array[1] + d, new, &c))
		&& !(asm_is_dir(array[1] + d, new, 2, &c)))
		asm_lc_error(strct);
	asm_save_arg(array[1] + d, strct, new->name, &len, c);
	d = asm_str_browse(array[2]);
	if (!(asm_is_reg(array[2] + d, new, &c)))
		asm_lc_error(strct);
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
	if (!(asm_is_reg(array[0], new, &c)))
		asm_lc_error(strct);
	asm_save_arg(array[0], strct, new->name, &len, c);
	d = asm_str_browse(array[1]);
	if (!(asm_is_reg(array[1] + d, new, &c))
		&& !(asm_is_dir(array[1] + d, new, 2, &c))
		&& !(asm_is_ind(array[1] + d, new, &c)))
		asm_lc_error(strct);
	asm_save_arg(array[1] + d, strct, new->name, &len, c);
	d = asm_str_browse(array[2]);
	if (!(asm_is_reg(array[2] + d, new, &c))
		&& !(asm_is_dir(array[2] + d, new, 2, &c)))
		asm_lc_error(strct);
	asm_save_arg_finish(array[2] + d, array[3], strct, new->name, &len, c);
	new->len += 2;
}

void	asm_aff(char **array, t_strct *strct, t_byteline *new, int len)
{
	int		c;

	if (!array[0])
		asm_lc_error(strct);
	if (!(asm_is_reg(array[0], new, &c)))
		asm_lc_error(strct);
	else
		asm_save_arg_finish(array[0], array[1], strct, new->name, &len, c);
	new->len += 2;
}
