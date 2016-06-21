/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:47:39 by pabril            #+#    #+#             */
/*   Updated: 2016/06/21 19:44:05 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				and(t_war *war, t_champ *champ)
{
	t_ocp 		ocp;
	t_return	p1;
	t_return	p2;
	t_return 	p3;

	//TODO ok ?

	champ->carry = 0;
	ocp = get_ocp(war->ram[calc_pc(champ->pc, + 1)]);
	champ->tmp_pc = calc_pc(champ->pc, 2);
	champ->carry = 0;
	p1 = get_param(war, define_params_types(REG_CODE, DIR_CODE, IND_CODE, def_opt(0, 1, 1)), ocp.first, champ);
	p2 = get_param(war, define_params_types(REG_CODE, DIR_CODE, IND_CODE, def_opt(0, 1, 1)), ocp.second, champ);
	p3 = get_param(war, define_params_types(REG_CODE, -1, -1, def_opt(0, 0, 1)), ocp.third, champ);

	if (!p1.error && !p2.error && !p3.error)
	{
		if ((p1.value & p2.value) == 0)
			champ->carry = 1;
		champ->reg_tab[p3.value - 1] = p1.value & p2.value;
	}
	champ->pc = champ->tmp_pc;
	return (0);
}
