/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 18:07:20 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/13 19:27:50 by vbarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int asm_check_comment(char *str)
{
	if (str[0] == COMMENT_CHAR)
		return (1);
	return (0);
}

int asm_check_live_zjmp_fork(char **tab)
{
	if (tab[1][0] != '%')
		return(1);
	if (tab[2] && !asm_check_comment(tab[2]))
		return(2);
	return(0)
}

int asm_check_ld(char **tab)
{
	if (tab[1][0] != '%' && !ft_atoi(tab[1]))
		return(1);
    if (tab[2][0] != 'r')
		return(2);
	if (tab[3] && !asm_check_comment(tab[3]))
        return(3);
	return (0);
}

int asm_check_st(char **tab)
{
	if (tab[1][0] != 'r')
        return(1);
    if (!ft_atoi(tab[2]) && tab[2][0] != 'r')
        return(2);
    if (tab[3] && !asm_check_comment(tab[3]))
        return(3);
	return (0);
}

int asm_check_add_sub(char **tab)
{
    if (tab[1][0] != 'r')
        return(1);
    if (tab[2][0] != 'r')
        return(2);
	if (tab[3][0] != 'r')
		return(3);
    if (tab[4] && !asm_check_comment(tab[4]))
		return(4);
	return (0);
}
