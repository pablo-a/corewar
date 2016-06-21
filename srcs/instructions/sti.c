/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:49:52 by pabril            #+#    #+#             */
/*   Updated: 2016/06/18 22:11:22 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				sti(t_war *war, t_champ *champ)
{
	t_ocp 		ocp;
	t_return	val1;
	t_return	val2;
	t_return 	reg;

	//TODO increment champ pc correctly when there is an error (now just increment by next)
	int next;
	next = 1;

	ocp = get_ocp(war->ram[calc_pc(champ->pc, next)]);
	champ->tmp_pc = calc_pc(champ->pc, 2);
	reg = get_param(war, define_params_types(REG_CODE, -1, -1, def_opt(0, 1, 0)), ocp.first, champ);
	if (reg.error && (champ->pc = calc_pc(champ->pc, next)))
		return (-1);
	val1 = get_param(war, define_params_types(REG_CODE, DIR_CODE, IND_CODE, def_opt(1, 1, 1)), ocp.second, champ);
	if (val1.error && (champ->pc = calc_pc(champ->pc, next)))
		return (-1);
	val2 = get_param(war, define_params_types(REG_CODE, DIR_CODE, -1, def_opt(1, 1, 0)), ocp.third, champ);
	if (val2.error && (champ->pc = calc_pc(champ->pc, next)))
		return (-1);

	int value1 = (val1.value + val2.value) % IDX_MOD;
	int value2 = calc_pc(champ->pc, value1);

	write_ram(war, reg.value, value2);
	champ->pc = champ->tmp_pc;

	//TODO modify carry ?
	champ->carry = 1;
	return (0);
}