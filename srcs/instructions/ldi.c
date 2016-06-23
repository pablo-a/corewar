/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:48:22 by pabril            #+#    #+#             */
/*   Updated: 2016/06/23 17:17:53 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ldi(t_war *war, t_champ *champ)
{
	t_ocp		ocp;
	t_return	p1;
	t_return	p2;
	t_return	p3;

	ocp = get_ocp(war->ram[calc_pc(champ->pc, 1)]);
	champ->tmp_pc = calc_pc(champ->pc, 2);
	p1 = get_param(war, define_params_types(REG_CODE, DIR_CODE, IND_CODE,
				def_opt(1, 1, 1)), ocp.first, champ);
	p2 = get_param(war, define_params_types(REG_CODE, DIR_CODE, -1,
				def_opt(1, 1, 1)), ocp.second, champ);
	p3 = get_param(war, define_params_types(REG_CODE, -1, -1,
				def_opt(0, 0, 0)), ocp.third, champ);
	if (!p1.error && !p2.error && !p3.error)
		champ->reg_tab[p3.value - 1] = get_value(war, calc_pc(champ->pc,
					(p1.value + p2.value) % IDX_MOD), 4);
	refresh_pc(war, champ, champ->pc, champ->tmp_pc);
	champ->pc = champ->tmp_pc;
	return (0);
}
