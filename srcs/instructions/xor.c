/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:50:10 by pabril            #+#    #+#             */
/*   Updated: 2016/06/21 19:45:18 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		xor(t_war *war, t_champ *champ)
{
	t_ocp 		ocp;
	t_return	val1;
	t_return	val2;
	t_return 	reg;
	int 		next;


	//TODO CHECK BY MARIUS

	//TODO increment champ pc correctly when there is an error (now just increment by next)
	next = 1;

	champ->carry = 0;
	ocp = get_ocp(war->ram[calc_pc(champ->pc, + next)]);
	champ->tmp_pc = calc_pc(champ->pc, 2);
	champ->carry = 0;
	val1 = get_param(war, define_params_types(REG_CODE, DIR_CODE, IND_CODE, def_opt(0, 1, 1)), ocp.first, champ);
	if (val1.error && (champ->pc = calc_pc(champ->pc, next)))
		return (-1);

	val2 = get_param(war, define_params_types(REG_CODE, DIR_CODE, IND_CODE, def_opt(0, 1, 1)), ocp.second, champ);
	if (val2.error && (champ->pc = calc_pc(champ->pc, next)))
		return (-1);

	reg = get_param(war, define_params_types(REG_CODE, -1, -1, def_opt(0, 0, 1)), ocp.third, champ);
	if (reg.error && (champ->pc = calc_pc(champ->pc, next)))
		return (-1);

	if (val1.value ^ val2.value == 0)
		champ->carry = 1;
	champ->reg_tab[reg.value - 1] = val1.value ^ val2.value;
	champ->pc = champ->tmp_pc;
	return (0);
}
