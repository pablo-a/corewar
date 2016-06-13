/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:49:42 by pabril            #+#    #+#             */
/*   Updated: 2016/06/13 22:49:18 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_return	get_first(int ocp, int *current_pos, t_war *war, t_champ *champ)
{
	int tmp;
	t_return val;
	int offset;

	val.value = 0;
	tmp = (ocp & 192) >> 6;//192 == 0b11000000
	if (tmp == REG_CODE)
	{
		if ((val.value = get_value(war, *current_pos, 1)) < 1 || val.value > 16)
			val.error = 1;
		val.value = champ->reg_tab[val.value - 1];
		*current_pos += 1;
	}
	else
		val.error = 1;
	return (val);
}

static t_return	get_second(int ocp, int *current_pos, t_war *war, t_champ *champ)
{
	int tmp;
	t_return val;
	int offset;

	val.value = 0;
	val.error = 0;
	tmp = ((ocp << 2) & 192) >> 6;//0b11000000
	if (tmp == REG_CODE)
	{
		if ((val.value = get_value(war, *current_pos, 1)) < 1 || val.value > 16)
			val.error = 1;
		*current_pos += 1;
	}
	else if (tmp == IND_CODE)
	{
		offset = (get_value(war, *current_pos, 2) + champ->pc) % MEM_SIZE;
		if (offset < 0)
			offset = MEM_SIZE + offset;
		val.value = get_value(war, offset, 4);
		*current_pos += 2;
	}
	else
		val.error = 1;
	return (val);
}

static int		go_next(int ocp)
{
	int result;
	int tmp;

	result = 0;
	result++;
	tmp = ((ocp << 2) & 192) >> 6;//0b11000000
	if (tmp == REG_CODE)
		result += 1;
	else if (tmp == IND_CODE)
		result += 2;
	return (result + 2);
}

static int		write_into_ram(t_war *war, int pos, int nb)
{
	war->ram[pos] = (nb & 0xFF000000) >> 24;
	war->ram[pos + 1] = (nb & 0xFF0000) >> 16;
	war->ram[pos + 2] = (nb & 0xFF00) >> 8;
	war->ram[pos + 3] = (nb & 0xFF);
	return (1);
}

int				st(t_war *war, t_champ *champ)
{
	int			current_pos;
	int			ocp;
	t_return	val1;
	t_return	val2;
	int			tmp;

	current_pos = champ->pc + 2;
	ocp = war->ram[current_pos - 1];
	val1 = get_first(ocp, &current_pos, war, champ);
	val2 = get_second(ocp, &current_pos, war, champ);
	if (val1.error == 1 || val2.error == 1)
	{
		champ->pc += go_next(ocp);
		return (-1);
	}
	if ((tmp = ((ocp << 2) & 192) >> 6) == REG_CODE)
		champ->reg_tab[val2.value] = val1.value;
	else
		write_into_ram(war, (val2.value % IDX_MOD), val1.value);
	champ->pc += (current_pos - champ->pc);
	return (0);
}
