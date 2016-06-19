/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 17:25:41 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/19 22:21:00 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

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
