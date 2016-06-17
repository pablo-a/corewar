/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:47:24 by pabril            #+#    #+#             */
/*   Updated: 2016/06/14 02:03:10 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		aff(t_war *war, t_champ *champ)
{
	int reg;
	int content;

	reg = war->ram[calc_pc(champ->pc, 2)];
	if (reg < 1 || reg > 16)
	{
		champ->pc = calc_pc(champ->pc, 3);
		return (-1);
	}
	content = champ->reg_tab[reg - 1] % 256;
	champ->pc = calc_pc(champ->pc, 3);
	//TODO Remove :
	ft_printf("aff : %#x ", content);
	ft_printf("%hhu ", content);
	ft_printf("Char is : %c\n", content);
	return (0);
}
