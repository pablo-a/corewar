/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:49:10 by pabril            #+#    #+#             */
/*   Updated: 2016/06/18 21:52:42 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			lld(t_war *war, t_champ *champ)
{
	t_return	val;
	t_return	reg;
	t_ocp		ocp;
	int			next;


	//TODO CHECK IT BY MARIUS

	//TODO: increment champ pc correctly when error (not just next)
	next = 1;
	ocp = get_ocp(war->ram[calc_pc(champ->pc, next)]);
	champ->tmp_pc = calc_pc(champ->pc, 2);
	val = get_param(war, define_params_types(-1, DIR_CODE, IND_CODE, def_opt(0, 0, 1)), ocp.first, champ);
	if (val.error && (champ->pc = calc_pc(champ->pc, next)))
				return (-1);
	reg = get_param(war, define_params_types(REG_CODE, -1, -1, def_opt(0, 0, 1)), ocp.second, champ);
	if (reg.error && (champ->pc = calc_pc(champ->pc, next)))
				return (-1);
	//ft_printf("val %d\n", val.value);
	//ft_printf("reg %d\n\n", reg.value);
	champ->reg_tab[reg.value - 1] = val.value;
	champ->pc = champ->tmp_pc;
	//TODO check carry how to change value.
	champ->carry = 1;
	return (0);
}
