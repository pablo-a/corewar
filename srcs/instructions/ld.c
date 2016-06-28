/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:48:14 by pabril            #+#    #+#             */
/*   Updated: 2016/06/23 17:17:02 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			ld(t_war *war, t_champ *champ)
{
	t_return	p1;
	t_return	p2;
	t_ocp		ocp;

	ocp = get_ocp(war->ram[calc_pc(champ->pc, 1)]);
	champ->tmp_pc = calc_pc(champ->pc, 2);
	p1 = get_param(war, define_params_types(-1, DIR_CODE, IND_CODE,
				def_opt(0, 0, 1)), ocp.first, champ);
	p2 = get_param(war, define_params_types(REG_CODE, -1, -1,
				def_opt(0, 0, 0)), ocp.second, champ);
	if (!p1.error && !p2.error)
	{
		if (p1.value == 0)
			champ->carry = 1;
		else
			champ->carry = 0;
		champ->reg_tab[p2.value - 1] = p1.value;
	}
	refresh_pc(war, champ, champ->pc, champ->tmp_pc);
	champ->pc = champ->tmp_pc;
	return (0);
}
