/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 19:36:21 by pabril            #+#    #+#             */
/*   Updated: 2016/06/15 16:13:45 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "corewar.h"
#include <ncurses.h>

int		error(char *str)
{
	ft_putendl(str);
	ft_putendl(USAGE);
	exit(0);
}

int		perror_exit(char *error)
{
	perror(error);
	exit(0);
}

int		display_ram(unsigned char ram[MEM_SIZE])
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (ram[i] != 0)
			ft_putstr(RED);
		if (ram[i] == 0)
			ft_putstr(END);
		if (i % 32 == 31)
			ft_printf("%02x\n", ram[i]);
		else
			ft_printf("%02x ", ram[i]);
		i++;
	}
	return (0);
}

int		display_reg(t_champ *champ)
{
	int		i;

	i = 0;
	ft_printf("champions : %s\n", champ->header->prog_name);
	while (i < REG_NUMBER)
	{
		ft_printf("registre %d : %#x\n", i, champ->reg_tab[i]);
		i++;
	}
	ft_putstr("\n");
}
