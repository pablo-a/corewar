/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:47:39 by pabril            #+#    #+#             */
/*   Updated: 2016/06/13 11:10:44 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libftprintf.h"

static int	get_first(int ocp, int *current_pos, t_war *war, t_champ *champ)
{
	int tmp;
	int val;
	int offset;

	val = 0;
	tmp = (ocp & 192) >> 6;//192 == 0b11000000
	if (tmp == REG_CODE)
	{
		val = get_value(war, *current_pos, 1);
		val = champ->reg_tab[val];
		*current_pos += 1;
	}
	else if (tmp == DIR_CODE)
	{
		val = get_value(war, *current_pos, 4);
		*current_pos += 4;
	}
	else if (tmp == IND_CODE)
	{
		offset = (get_value(war, *current_pos, 2) + champ->pc) % MEM_SIZE;
		if (offset < 0)
			offset = MEM_SIZE - offset;
		val = get_value(war, offset, 4);
		*current_pos += 2;
	}
	return (val);
}

static int	get_second(int ocp, int *current_pos, t_war *war, t_champ *champ)
{
	int tmp;
	int val;
	int offset;

	val = 0;
	tmp = ((ocp << 2) & 192) >> 6;//0b11000000
	if (tmp == REG_CODE)
	{
		val = get_value(war, *current_pos, 1);
		val = champ->reg_tab[val];
		*current_pos += 1;
	}
	else if (tmp == DIR_CODE)
	{
		val = get_value(war, *current_pos, 4);
		*current_pos += 4;
	}
	else if (tmp == IND_CODE)
	{
		offset = (get_value(war, *current_pos, 2) + champ->pc) % MEM_SIZE;
		if (offset < 0)
			offset = MEM_SIZE - offset;
		val = get_value(war, offset, 4);
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

	current_pos = champ->pc + 2;
	ocp = war->ram[current_pos - 1];
	val1 = get_first(ocp, &current_pos, war, champ);
	val2 = get_second(ocp, &current_pos, war, champ);
	reg = get_value(war, current_pos, 1);
	current_pos++;
	champ->reg_tab[reg - 1] = val1 & val2;
	champ->pc += (current_pos - champ->pc);
	champ->carry = 1;
	return (0);
}
