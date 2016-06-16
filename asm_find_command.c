/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 00:22:51 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/16 18:02:37 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_find_command(char *command, t_strct *strct)
{
	int x;

	x = 0;
	while (ft_strcmp(strct->tab_command[x], command))
		x++;
	if (x < 17)
		return (x);
	else
		return (-1);
}

int		asm_label_size(char *command)
{
	if (!ft_strcmp(command, "live"))
		return (4);
	else if (!ft_strcmp(command, "ld"))
		return (4);
	else if (!ft_strcmp(command, "st"))
		return (2);
	else if (!ft_strcmp(command, "add"))
		return (2);
	else if (!ft_strcmp(command, "sub"))
		return (2);
	else if (!ft_strcmp(command, "and"))
		return (4);
	else if (!ft_strcmp(command, "or"))
		return (4);
	else if (!ft_strcmp(command, "xor"))
		return (4);
	else if (!ft_strcmp(command, "zjmp"))
		return (2);
	else if (!ft_strcmp(command, "ldi"))
		return (2);
	else if (!ft_strcmp(command, "sti"))
		return (2);
	else if (!ft_strcmp(command, "fork"))
		return (2);
	else if (!ft_strcmp(command, "lld"))
		return (4);
	else if (!ft_strcmp(command, "lldi"))
		return (2)
	else if (!ft_strcmp(command, "lfork"))
		return (2);
	else if (!ft_strcmp(command, "aff"))
		return (2);
	else
		asm_error("Apprend a ecrire petit scarabe");
	return (-1);
}
