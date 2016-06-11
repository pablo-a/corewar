/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 00:22:51 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/11 19:09:52 by vbarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char 	**asm_list_command()
{
	char **tab_command;
	int x;
	
	tab_command = (char**)malloc(sizeof(char*)*16);
	x = 0;
	tab_command[0] = ft_strdup("live");
	tab_command[1] = ft_strdup("ld");
	tab_command[2] = ft_strdup("st");
	tab_command[3] = ft_strdup("add");
	tab_command[4] = ft_strdup("sub");
	tab_command[5] = ft_strdup("and");
	tab_command[6] = ft_strdup("or");
	tab_command[7] = ft_strdup("xor");
	tab_command[8] = ft_strdup("zjmp");
	tab_command[9] = ft_strdup("ldi");
	tab_command[10] = ft_strdup("sti");
	tab_command[11] = ft_strdup("fork");
	tab_command[12] = ft_strdup("lld");
	tab_command[13] = ft_strdup("lldi");
	tab_command[14] = ft_strdup("lfork");
	tab_command[15] = ft_strdup("aff");
	return (tab_command);
}

int		asm_find_command(char *command, int fd)
{
	char **tab_command;
	int x;

	tab_command = asm_list_command();
	x = 0;
	fd = 1;
	while (x < 16)
	{
		if (!strcmp(command, tab_command[x]))
		{
			
			if (x < 8 || x == 12)
				return (4);
			return (2);
		}
		x++;
	}
	asm_error("Commande Invalide");
	return (0);
}
