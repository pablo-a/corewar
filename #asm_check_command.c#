/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 18:07:20 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/15 11:50:43 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int asm_check_comment(char *str)
{
	if (str[0] == COMMENT_CHAR)
		return (1);
	return (0);
}

int asm_check_live_zjmp_fork(char **tab)
{
	if (!asm_is_dir(tab[0]))
		return(1);
	if (tab[1] && !asm_check_comment(tab[1]))
		return(2);
	return(0);
}

int asm_check_ld(char **tab)
{
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
