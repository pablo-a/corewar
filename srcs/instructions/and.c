/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:47:39 by pabril            #+#    #+#             */
/*   Updated: 2016/06/11 18:00:32 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libftprintf.h"

int		and(t_war *war, t_champ *champ)
{
	int current_pos;
	int ocp;
	int tmp;
	int val;
	int reg;

	current_pos = champ->pc + 1;
	ocp = war->ram[current_pos];
	while (ocp > 0)
	{
		tmp = (ocp & 0xff000000) >> 24;
		current_pos++;
		if (tmp == REG_CODE && (current_pos += 1))
			val = get_value(war, current_pos, 1);
		else if (tmp == DIR_CODE && (current_pos += 4))
			val = get_value(war, current_pos, 4);
		else if (tmp == IND_CODE && (current_pos += 2))
			val = get_value(war, current_pos, 2);
	}
	return (0);
}
