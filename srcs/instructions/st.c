/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:49:42 by pabril            #+#    #+#             */
/*   Updated: 2016/06/18 22:11:19 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		st(t_war *war, t_champ *champ)
{
	t_ocp		ocp;
	t_return	reg;
	t_return	val;

	//TODO pc value if error and carry to solve :
	int			next;
	next = 1;

	ocp = get_ocp(war->ram[calc_pc(champ->pc, next)]);
	champ->tmp_pc = calc_pc(champ->pc, 2);
	reg = get_param(war, define_params_types(REG_CODE, -1, -1, def_opt(0, 1, 0)),
			ocp.first, champ);
	if (reg.error && (champ->pc = calc_pc(champ->pc, next)))
		return (-1);
	val = get_param(war, define_params_types(REG_CODE, -1, IND_CODE,
				def_opt(1, 0, 0)), ocp.second, champ);
	if (val.error && (champ->pc = calc_pc(champ->pc, next)))
		return (-1);
	write_ram(war, reg.value, calc_pc(champ->pc, (val.value % IDX_MOD)));
	champ->pc = champ->tmp_pc;

	//TODO CARRY ?

	return (0);
}
