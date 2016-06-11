/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 17:25:41 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/11 00:29:16 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
	{
		asm_error("Pas assez d'argument");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) != -1)
		asm_parse(fd, asm_find_file_name(av[1]));
	else
		asm_error("Fichier Inexistant");
	close(fd);
	return (0);
}
