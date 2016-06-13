/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:49:59 by pabril            #+#    #+#             */
/*   Updated: 2016/06/13 18:49:08 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		sub(t_war *war, t_champ *champ)
{
	int r1;
	int r2;
	int r3;

	r1 = war->ram[calc_pc(champ->pc, 2)] - 1;
	r2 = war->ram[calc_pc(champ->pc, 3)] - 1;
	r3 = war->ram[calc_pc(champ->pc, 4)] - 1;
	if (r1 > 15 || r1 < 0 || r2 < 0 || r2 > 15 || r3 > 15 || r3 < 0)
	{
		champ->carry = 0;
		champ->pc = calc_pc(champ->pc, 5);
		return (-1);
	}
	champ->reg_tab[r3] = champ->reg_tab[r1] - champ->reg_tab[r2];
	champ->carry = 1;
	champ->pc = calc_pc(champ->pc, 5);
	return (0);
}
