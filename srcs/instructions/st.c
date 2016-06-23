/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:49:42 by pabril            #+#    #+#             */
/*   Updated: 2016/06/23 17:20:14 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		st(t_war *war, t_champ *champ)
{
	t_ocp		ocp;
	t_return	p1;
	t_return	p2;

	ocp = get_ocp(war->ram[calc_pc(champ->pc, 1)]);
	champ->tmp_pc = calc_pc(champ->pc, 2);
	p1 = get_param(war, define_params_types(REG_CODE, -1, -1, def_opt(0, 1, 0)),
			ocp.first, champ);
	p2 = get_param(war, define_params_types(REG_CODE, -1, IND_CODE,
				def_opt(1, 0, 0)), ocp.second, champ);
	if (!p1.error && !p2.error && ocp.second == IND_CODE)
		write_ram(war, champ, p1.value, calc_pc(champ->pc,
					(p2.value % IDX_MOD)));
	else if (!p1.error && !p2.error && ocp.second == REG_CODE)
		champ->reg_tab[p2.value -1] = champ->reg_tab[p1.value -1];

	refresh_pc(war, champ, champ->pc, champ->tmp_pc);
	champ->pc = champ->tmp_pc;
	return (0);
}
