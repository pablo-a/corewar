/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 19:36:21 by pabril            #+#    #+#             */
/*   Updated: 2016/06/10 22:24:48 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "corewar.h"

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
		if (i % 32 == 31)
		{
			ft_printf("%02x\n", ram[i]);
			i++;
		}
		else
			ft_printf("%02x ", ram[i]);
		i++;
	}
}
