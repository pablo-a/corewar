/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:49:52 by pabril            #+#    #+#             */
/*   Updated: 2016/06/13 23:15:35 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void write_ram(t_war *war, int value, int address)
{
	int i;
	int bit;

	i = -1;
	while(++i < 4)
	{
		bit = (value >> ( 8 * (i + 1))) & 0xff;
		war->ram[(address + i) % MEM_SIZE] = (unsigned char)bit;
	}
}

int				sti(t_war *war, t_champ *champ)
{
	t_opc 		ocp;
	t_return	val1;
	t_return	val2;
	t_return 	reg;
	int 		next;

	//TODO increment champ pc correctly when there is an error (now just increment by next)
	next = 1;

	//TODO Check why second param can be DIR and third not,

	ocp = get_opc(war->ram[calc_pc(champ->pc, + next)]);
	champ->tmp_pc = calc_pc(champ->pc, 2);

	reg = get_param(war, define_params_types(REG_CODE, -1, -1, 0), ocp.first, champ);
	if (reg.error && (champ->pc = calc_pc(champ->pc, next)))
		return (-1);

	val1 = get_param(war, define_params_types(REG_CODE, DIR_CODE, IND_CODE, 1), ocp.second, champ);
	if (reg.error && (champ->pc = calc_pc(champ->pc, next)))
		return (-1);

	val2 = get_param(war, define_params_types(REG_CODE, DIR_CODE, -1, 1), ocp.third, champ);
	if (reg.error && (champ->pc = calc_pc(champ->pc, next)))
		return (-1);

	write_ram(war, reg.value, (val1.value + val2.value) % MEM_SIZE);
	champ->pc = champ->tmp_pc;
	return (0);
}
