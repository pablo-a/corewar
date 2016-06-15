/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_command_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 18:58:49 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/15 12:58:39 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int asm_check_and_or(char **tab)
{
    if (!asm_is_reg(tab[0]) && !asm_is_dir(tab[0]) && !asm_is_ind(tab[0]))
		return(1);
    if (!asm_is_reg(tab[1]) && !asm_is_dir(tab[1]) && !asm_is_ind(tab[1]))
		return(2);
    if (!asm_is_reg(tab[2]))
        return(3);
    if (tab[3] && !asm_check_comment(tab[3]))
		return(4);
	return (0);
}

int asm_check_ldi(char **tab)
{
    if (!asm_is_reg(tab[0]) && !asm_is_dir(tab[0]) && !asm_is_ind(tab[0]))
        return(1);
    if (!asm_is_reg(tab[1]) && !asm_is_dir(tab[1]))
		return(2);
    if (!asm_is_reg(tab[2]))
		return(3);
    if (tab[3] && !asm_check_comment(tab[3]))
		return(4);
	return (0);
}

int asm_check_sti(char **tab)
{
    if (!asm_is_reg(tab[0]))
        return(1);
    if (!asm_is_reg(tab[1]) && !asm_is_dir(tab[1]) && !asm_is_ind(tab[1]))
		return(2);
    if (!asm_is_reg(tab[2]) && !asm_is_dir(tab[2]))
		return(3);
    if (tab[3] && !asm_check_comment(tab[3]))
		return(4);
	return (0);
}

int asm_check_aff(char **tab)
{
	if (!asm_is_reg(tab[0]))
		return (1);
	if (tab[1] && !asm_check_comment(tab[1]))
		return (2);
	return (0);
}

int asm_check_command(int i, char *str, t_strct *strct)//char **tab)
{
	t_byteline *new;
	int			ret;

	if (i == -1 || !str || !strct)
	{
		ft_putendl("Pablo suce des *****!");
		exit(0);
	}
	ret = 1;
	new = (t_byteline*)malloc(sizeof(t_byteline));
	new->next = NULL;
	new->label = 0; //
//	ft_putendl(str + strct->c);
//	exit(0); 
/*
	if (i == 0 || i == 8 || i == 11 || i == 14)
		ret = asm_check_live_zjmp_fork();
	else if (i == 1 || i == 12)
		ret = asm_check_ld(arg);
	else if (i == 2)
		ret = asm_check_st(arg);
	else if (i == 3 || i == 4)
		ret = asm_check_add_sub(arg);
	else if (i > 4 || i < 8)
		ret = asm_check_and_or(arg);
	else if (i == 9 || i == 13)
		ret = asm_check_ldi(arg);
	else if (i == 10)
		ret = asm_check_sti(arg);
	else if (i == 15)
		ret = asm_check_aff(arg); 
	if (ret == 0)
			 save -> new -> in -> byteline */
	return (ret);
}
