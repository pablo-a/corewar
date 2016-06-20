/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:47:24 by pabril            #+#    #+#             */
/*   Updated: 2016/06/18 20:38:26 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		aff(t_war *war, t_champ *champ)
{
	t_ocp 		ocp;
	t_return 	reg;
	int 		next;

	ft_printf("AFF\n");

	//TODO increment champ pc correctly when there is an error (now just increment by next)
	next = 1;

	ocp = get_ocp(war->ram[calc_pc(champ->pc, + next)]);
	champ->tmp_pc = calc_pc(champ->pc, 2);
	reg = get_param(war, define_params_types(REG_CODE, -1, -1, def_opt(0, 1, 0)), ocp.first, champ);
	if (reg.error && (champ->pc = calc_pc(champ->pc, next)))
	{
		ft_printf("Aff fail \n");
		return (-1);
	}
	champ->pc = champ->tmp_pc;
	ft_putchar((char)(reg.value % 256));
	return (0);
}
