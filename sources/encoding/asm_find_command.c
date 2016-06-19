/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 00:22:51 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/19 22:21:43 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int		asm_find_command(char *command, t_strct *strct)
{
	int		x;

	x = 0;
	while (ft_strcmp(strct->tab_command[x], command))
		x++;
	if (x < 17)
		return (x);
	else
		return (-1);
}

int		asm_label_size(char *command, t_strct *strct)
{
	int x;

	x = asm_find_command(command, strct);
	if (x == 0 || x == 1 || x == 5 || x == 6
		|| x == 7 || x == 12)
		return (4);
	if (x == -1)
		asm_error("Apprend a ecrire petit scarabe");
	return (2);
}
