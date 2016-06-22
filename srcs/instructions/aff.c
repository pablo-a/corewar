/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:47:24 by pabril            #+#    #+#             */
/*   Updated: 2016/06/22 03:33:36 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		aff(t_war *war, t_champ *champ)
{
	t_ocp 		ocp;
	t_return 	reg;

	//TODO ok ?

	ocp = get_ocp(war->ram[calc_pc(champ->pc, + 1)]);
	champ->tmp_pc = calc_pc(champ->pc, 2);
	reg = get_param(war, define_params_types(REG_CODE, -1, -1, def_opt(0, 1, 0)), ocp.first, champ);
	if (!reg.error && war->args->ncurse == 0)
	{
		ft_printf("AFF reg.value is : %d\n", reg.value);
		ft_putchar((char)(reg.value % 256));
	}
	refresh_pc(war, champ, champ->pc, champ->tmp_pc);
	champ->pc = champ->tmp_pc;
	return (0);
}
