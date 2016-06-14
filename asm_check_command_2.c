/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_command_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 18:58:49 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/14 14:55:59 by vbarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int asm_check_command(int i, char **tab, t_byteline byteline)
{
	int x;
	int ret;
	char *str;
	char **arg;

	str = tab[1];
	x = 2;
	ret = 0;
	while(tab[x++])
		str = ft_strjoin(str, tab[x]);
	arg = ft_strsplit(str, SEPARATOR_CHAR);
	if (i == 0 || i == 8 || i == 11 || i == 14)
		ret = asm_check_live_zjmp_fork(arg);
	if (i == 1 || i == 12)
		ret = asm_check_ld(arg);
	if (i == 2)
		ret = asm_check_st(arg);
	if (i == 3 || i == 4)
		ret = asm_check_add_sub(arg);
	if (i > 4 || i < 8)
		ret = asm_check_and_or(arg);
	if (i == 9 || i == 13)
		ret = asm_check_ldi(arg);
	if (i == 11)
		ret = asm_check_sti(arg);
	if (i == 15)
		ret = asm_check_aff(arg);
//  Si ret est different de 0, c'est une erreur est la fonction le renvoye.
	if (ret != 0)
		return (ret);
//  Suite du code a faire
}
