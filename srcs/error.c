/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 19:36:21 by pabril            #+#    #+#             */
/*   Updated: 2016/06/24 05:22:48 by pabril           ###   ########.fr       */
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

int		display_ram(unsigned char ram[MEM_SIZE], int ram_info[MEM_SIZE])
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (ram_info[i] != 0)
			ft_putstr(RED);
		if (ram_info[i] == 0)
			ft_putstr(END);
		//TODO put back to 32 :
		if (i % 64 == 63)
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
	return (0);
}

int		display_ram_info(int ram_info[MEM_SIZE])
{
	int i;

	i = 0;
	ft_printf("\nMEMORY_INFO :\n");
	while (i < MEM_SIZE)
	{
		if (ram_info[i] != 0)
			ft_putstr(GREEN);
		if (ram_info[i] == 0)
			ft_putstr(END);
		if (i % 32 == 31)
			ft_printf("%02x\n", ram_info[i]);
		else
			ft_printf("%02x ", ram_info[i]);
		i++;
	}
	return (0);
}
