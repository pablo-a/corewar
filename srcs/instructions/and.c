/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:47:39 by pabril            #+#    #+#             */
/*   Updated: 2016/06/11 19:24:03 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libftprintf.h"

static int	get_first(int ocp, int *current_pos, t_war *war)
{
	int tmp;
	int val;

	val = 0;
	tmp = (ocp & 192) >> 6;//192 == 0b11000000
	if (tmp == REG_CODE)
	{
		val = get_value(war, *current_pos, 1);
		*current_pos += 1;
	}
	else if (tmp == DIR_CODE)
	{
		val = get_value(war, *current_pos, 4);
		*current_pos += 4;
	}
	else if (tmp == IND_CODE)
	{
		val = get_value(war, *current_pos, 2);
		*current_pos += 2;
	}
	return (val);
}

static int	get_second(int ocp, int *current_pos, t_war *war)
{
	int tmp;
	int val;

	val = 0;
	tmp = ((ocp << 2) & 192) >> 6;//0b11000000
	if (tmp == REG_CODE)
	{
		val = get_value(war, *current_pos, 1);
		*current_pos += 1;
	}
	else if (tmp == DIR_CODE)
	{
		val = get_value(war, *current_pos, 4);
		*current_pos += 4;
	}
	else if (tmp == IND_CODE)
	{
		val = get_value(war, *current_pos, 2);
		*current_pos += 2;
	}
	return (val);
}

int		and(t_war *war, t_champ *champ)
{
	int current_pos;
	int ocp;
	int val1;
	int val2;
	int reg;

	current_pos = champ->pc + 1;
	ocp = war->ram[current_pos];
	current_pos++;
	val1 = get_first(ocp, &current_pos, war);
	val2 = get_second(ocp, &current_pos, war);
	reg = get_value(war, current_pos, 1);
	current_pos++;
	champ->reg_tab[reg - 1] = val1 & val2;
	champ->pc += (current_pos - champ->pc);
	return (0);
}
