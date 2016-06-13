/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:48:14 by pabril            #+#    #+#             */
/*   Updated: 2016/06/13 14:06:54 by pabril           ###   ########.fr       */
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
		if ((val = get_value(war, *current_pos, 1)) < 1 || val > 16)
			return (ERROR);
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
			offset = MEM_SIZE + offset;
		val = get_value(war, offset, 4);
		*current_pos += 2;
	}
	else
		return (ERROR);
	return (val);
}

static int	go_next(int ocp)
{
	int result;
	int tmp;

	result = 0;
	tmp = (ocp & 192) >> 6;//192 == 0b11000000
	if (tmp == REG_CODE)
		result += 1;
	else if (tmp == DIR_CODE)
		result += 4;
	else if (tmp == IND_CODE)
		result += 2;
	else
		return (result);
	tmp = ((ocp << 2) & 192) >> 6;//0b11000000
	if (tmp == REG_CODE)
		result += 1;
	else if (tmp == DIR_CODE)
		result += 4;
	else if (tmp == IND_CODE)
		result += 2;
	else
		return (result + 2);// +2 : OCP et passer a la prochaine instruction.
	return (result);
}


int			ld(t_war *war, t_champ *champ)
{
	int val;
	int reg;
	int ocp;
	int current_pos;

	current_pos = champ->pc + 2;
	ocp = war->ram[current_pos - 1];
	val = get_first(ocp, &current_pos, war, champ);
	reg = war->ram[current_pos];
	current_pos++;
	if (val == ERROR || reg < 1 || reg > 16)
	{
		champ->pc += go_next(ocp);
		return (-1);
	}
	champ->reg_tab[reg - 1] = val;
	champ->pc += (current_pos - champ->pc);
	return (0);
}
