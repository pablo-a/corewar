/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 17:25:41 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/23 20:09:02 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		asm_clean_memory_2(t_strct *strct)
{
	t_str		*file;
	char		**tab;
	int			i;

	i = 0;
	file = strct->file;
	while (file)
	{
		free(file->str);
		free(file);
		file = file->next;
	}
	tab = strct->tab_command;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void		asm_clean_memory(t_strct *strct)
{
	t_byteline *ptr;

	asm_clean_memory_2(strct);
	free(strct->name);
	free(strct->comment);
	ptr = strct->bytelines;
	while (ptr)
	{
		if (ptr->label == 0)
			free(ptr->byte_line);
		free(ptr->name);
		free(ptr);
		ptr = ptr->next;
	}
	free(strct);
}

void		asm_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int			main(int ac, char **av)
{
	if (ac != 2)
	{
		asm_error("Pas assez d'argument");
		return (0);
	}
	if (asm_parse_file(av[1]) != 0)
		return (0);
	return (0);
}
