/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:48:14 by pabril            #+#    #+#             */
/*   Updated: 2016/06/13 12:13:38 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libftprintf.h"

int		ld(t_war *war, t_champ *champ)
{
	int val;
	int reg;
	int ocp;
	int current_pos;

	current_pos = champ->pc + 2;
	ocp = war->ram[current_pos - 1];
	val = get_first(ocp, &current_pos, war, champ);
	reg = war->ram[current_pos];
	if (reg < 1 || reg > 16)
	champ->reg_tab[reg - 1] = val;
	return (0);
}
