/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:49:52 by pabril            #+#    #+#             */
/*   Updated: 2016/06/22 03:48:05 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				sti(t_war *war, t_champ *champ)
{
	t_ocp 		ocp;
	t_return	val1;
	t_return	val2;
	t_return 	reg;

	//TODO OK ?

	ocp = get_ocp(war->ram[calc_pc(champ->pc, 1)]);
	champ->tmp_pc = calc_pc(champ->pc, 2);
	reg = get_param(war, define_params_types(REG_CODE, -1, -1, def_opt(0, 1, 0)), ocp.first, champ);
	val1 = get_param(war, define_params_types(REG_CODE, DIR_CODE, IND_CODE, def_opt(1, 1, 1)), ocp.second, champ);
	val2 = get_param(war, define_params_types(REG_CODE, DIR_CODE, -1, def_opt(1, 1, 0)), ocp.third, champ);
	if (!reg.error && !val1.error && !val2.error)
		write_ram(war, champ, reg.value, calc_pc(champ->pc, (val1.value + val2.value) % IDX_MOD));
	refresh_pc(war, champ, champ->pc, champ->tmp_pc);
	champ->pc = champ->tmp_pc;
	return (0);
}
