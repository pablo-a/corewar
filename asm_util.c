/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 21:58:45 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/11 23:42:36 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_list	*asm_lst_browse(t_list *lst, int c)
{
	while (lst && c--)
		lst = lst->next;
	return (lst);
}

int		asm_str_browse(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

void	*asm_lc_error(int l, int c)
{
	ft_putstr("ERROR: [");
	ft_putnbr(l + 1);
	ft_putstr(", ");
	ft_putnbr(c + 1);
	ft_putendl("]");
	exit(0);
}
