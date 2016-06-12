/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 03:35:54 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/13 00:12:41 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"



int				asm_check_command(t_str *lst, t_strct *strct)
{
	int x;
	int i;
	char *buff;

	buff = lst->str + strct->c;
	i = 0;
	while (buff[i] && buff[i] != ' ')
		i++;
	if (buff[i] != ' ' || i > 4)
		return (0);
	buff[i] = 0;
	x = 0;
	while (strct->tab_command[x])
	{
		if (!ft_strcmp(lst->str + strct->c, strct->tab_command[x]))
			{
				buff[i] = ' ';
				return (asm_add_command(lst, strct, x)); // TODO
			}
		x++;
	}
	if (x == 26)
		buff[i] = ' ';
	return (0);
}



t_str			*asm_check_label(t_str *lst, t_strct *strct)
{
	int i;

	i = 0;
	if (asm_check_command(lst, strct) != 0)
		return (lst->next);
	else
	{
		i = strct->c;
		while (ft_strchr(LABEL_CHARS, lst->str[strct->c]))
			strct->c += 1;
		if (lst->str[strct->c] != LABEL_CHAR)
			return (NULL);
		lst->str[strct->c] = 0;
		lst->str[strct->c] = ':';
		strct->c += 1;
		strct->c += asm_str_browse(lst->str + strct->c);
		if (!lst->str[strct->c] || lst->str[strct->c] == '#')
			return (lst->next);
		else if (asm_check_command(lst, strct) == 0) // HUM
			return (NULL);
	}
	return (NULL);
}
