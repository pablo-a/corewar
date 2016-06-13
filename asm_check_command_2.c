/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_command_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 18:58:49 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/13 20:04:41 by vbarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int asm_check_and_or(char **tab)
{
    if (tab[1][0] != 'r' && tab[1][0] != '%' && !ft_atoi(tab[1]))
		return(1);
    if (tab[2][0] != 'r' && tab[2][0] != '%' && !ft_atoi(tab[2]))
		return(2);
    if (tab[3][0] != 'r')
        return(3);
    if (tab[4] && !asm_check_comment(tab[4]))
		return(4);
	return (0);
}

int asm_check_ldi(char **tab)
{
    if (tab[1][0] != 'r' && tab[1][0] != '%' && !ft_atoi(tab[1]))
        return(1);
    if (tab[2][0] != 'r' && tab[2][0] != '%')
		return(2);
    if (tab[3][0] != 'r')
		return(3);
    if (tab[4] && !asm_check_comment(tab[4]))
		return(4);
	return (0);
}

int asm_check_sti(char **tab)
{
    if (tab[1][0] != 'r')
        return(1);
    if (tab[2][0] != 'r' && tab[2][0] != '%' && !ft_atoi(tab[2]))
		return(2);
    if (tab[3][0] != 'r' && tab[3][0] != '%' && !ft_atoi(tab[3]))
		return(3);
    if (tab[4] && !asm_check_comment(tab[4]))
		return(4);
	return (0);
}

int asm_check_aff(char **tab)
{
	if (tab[1][0] != 'r')
		return (1);
	if (tab[2] && !asm_check_comment(tab[2]))
		return (2);
	return (0);
}

int asm_check_command(int i, char **tab, t_byteline byteline)
{
	if (i == 0 || i == 8 || i == 11 || i == 14)
		return (asm_check_live_zjmp_fork(tab));
	if (i == 1 || i == 12)
		return (asm_check_ld(tab));
	if (i == 2)
		return (asm_check_st(tab));
	if (i == 3 || i == 4)
		return (asm_check_add_sub(tab));
	if (i > 4 || i < 8)
		return (asm_check_and_or(tab));
	if (i == 9 || i == 13)
		return (asm_check_ldi(tab));
	if (i == 11)
		return (asm_check_sti(tab));
	if (i == 15)
		return (asm_check_aff(tab));
	return (-1);
}
