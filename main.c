/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 17:25:41 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/12 02:46:57 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Gestion d erreur simple et exit
*/
void		asm_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

/*
** Rien d extra, je check que j qi bien un arg 2 et j avance
*/
int			main(int ac, char **av)
{
	if (ac != 2)
	{
		asm_error("Pas assez d'argument");
		return (0);
	}
	if (asm_parse_file(av[1]) != 0)
		return (0);
	// else create_file
	return (0);
}
