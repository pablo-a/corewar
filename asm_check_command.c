/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 18:07:20 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/16 16:22:04 by vbarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int asm_check_comment(char *str)
{
	if (str[0] == COMMENT_CHAR)
		return (1);
	return (0);
}

int asm_check_live_zjmp_fork(char **array, t_strct *strct, char *name, int len)
{
	int c;

	if (!array[0])
		asm_lc_error(strct);
	if (!(c = asm_is_dir(tab[0])))
		asm_lc_error(strct);
	else
		asm_save_arg_finish(array[0], array[1], strct, name, &len, c);
}

int asm_check_ld(char **array, t_strct *strct, char *name, int len)
{
	int c;
	int d;
	int kop1;

	kop1 = 0;
	while (array[kop1])
		kop1++;
	if (kop1 < 2)
		
	if (!asm_is_dir(tab[0]) && !asm_is_ind(tab[0]))
		return(1);
    if (!asm_is_reg(tab[1]))
		return(2);
	if (tab[2] && !asm_check_comment(tab[2]))
        return(3);
	return (0);
}

int asm_check_st(char **tab)
{
	if (!asm_is_reg(tab[0]))
        return(1);
    if (!asm_is_ind(tab[1]) && !asm_is_reg(tab[1]))
        return(2);
    if (tab[2] && !asm_check_comment(tab[2]))
        return(3);
	return (0);
}

int asm_check_add_sub(char **tab)
{
    if (!asm_is_reg(tab[0]))
        return(1);
    if (!asm_is_reg(tab[1]))
        return(2);
	if (!asm_is_reg(tab[2]))
		return(3);
    if (tab[3] && !asm_check_comment(tab[3]))
		return(4);
	return (0);
}
