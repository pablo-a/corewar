/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:46:33 by pabril            #+#    #+#             */
/*   Updated: 2016/06/18 20:42:07 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libftprintf.h"

int		add(t_war *war, t_champ *champ)
{
	t_ocp 	ocp;
	t_return r1;
	t_return r2;
	t_return r3;
	int 	next;

	//TODO increment champ pc correctly when there is an error (now just increment by next)
	//TODO HANDLE CARRY !

	ft_printf("ADD\n");

	next = 1;

	ocp = get_ocp(war->ram[calc_pc(champ->pc, + next)]);
	champ->tmp_pc = calc_pc(champ->pc, 2);

	r1 = get_param(war, define_params_types(REG_CODE, -1, -1, def_opt(0, 1, 0)), ocp.first, champ);
	if (r1.error && (champ->pc = calc_pc(champ->pc, next)))
		return (-1);

	r2 = get_param(war, define_params_types(REG_CODE, -1, -1, def_opt(0, 1, 0)), ocp.second, champ);
	if (r2.error && (champ->pc = calc_pc(champ->pc, next)))
		return (-1);

	r3 = get_param(war, define_params_types(REG_CODE, -1, -1, def_opt(0, 0, 0)), ocp.third, champ);
	if (r3.error && (champ->pc = calc_pc(champ->pc, next)))
		return (-1);

	champ->reg_tab[r3.value - 1] = r1.value + r2.value;
	champ->carry = 1;
	champ->pc = champ->tmp_pc;

	return (0);
}
