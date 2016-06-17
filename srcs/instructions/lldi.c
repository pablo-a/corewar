/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:49:20 by pabril            #+#    #+#             */
/*   Updated: 2016/06/13 22:53:15 by pabril           ###   ########.fr       */
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
		*current_pos = calc_pc(*current_pos, 1);
	}
	else if (tmp == DIR_CODE)
	{
		val.value = get_value(war, *current_pos, 2);
		*current_pos = calc_pc(*current_pos, 2);
	}
	else if (tmp == IND_CODE)
	{
		offset = calc_pc(get_value(war, *current_pos, 2), champ->pc);
		val.value = get_value(war, offset, 4);
		*current_pos = calc_pc(*current_pos, 2);
	}
	else
		val.error = 1;
	return (val);
}

static t_return	get_second(int ocp, int *current_pos, t_war *war, t_champ *champ)
{
	int tmp;
	t_return val;

	val.value = 0;
	val.error = 0;
	tmp = ((ocp << 2) & 192) >> 6;//0b11000000
	if (tmp == REG_CODE)
	{
		if ((val.value = get_value(war, *current_pos, 1)) < 1 || val.value > 16)
			val.error = 1;
		val.value = champ->reg_tab[val.value - 1];
		*current_pos = calc_pc(*current_pos, 1);
	}
	else if (tmp == DIR_CODE)
	{
		val.value = get_value(war, *current_pos, 2);
		*current_pos = calc_pc(*current_pos, 2);
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
	tmp = (ocp & 192) >> 6;//192 == 0b11000000
	if (tmp == REG_CODE)
		result += 1;
	else if (tmp == DIR_CODE)
		result += 2;
	else if (tmp == IND_CODE)
		result += 2;
	else
		return (result);
	tmp = ((ocp << 2) & 192) >> 6;//0b11000000
	if (tmp == REG_CODE)
		result += 1;
	else if (tmp == DIR_CODE)
		result += 2;
	else
		return (result + 3);// +3 : OCP et registre et +1 pour la forme.
	return (result);
}

int		lldi(t_war *war, t_champ *champ)
{
	int			current_pos;
	t_return	addr;
	t_return	addr2;
	int			reg;
	int			ocp;

	current_pos = calc_pc(champ->pc, 2);
	ocp = war->ram[calc_pc(current_pos, -1)];
	addr = get_first(ocp, &current_pos, war, champ);
	addr2 = get_second(ocp, &current_pos, war, champ);
	reg = get_value(war, current_pos, 1);
	current_pos = calc_pc(current_pos, 1);
	if (addr.error == 1 || addr2.error == 1 || reg < 1 || reg > 16)
	{
		champ->pc = calc_pc(champ->pc, go_next(ocp));
		champ->carry = 0;
		return (-1);
	}
	champ->reg_tab[reg - 1] = war->ram[(addr.value + addr2.value) % MEM_SIZE];
	//				==> valeur de l'addresse (somme des addresses)
	champ->pc = current_pos;
	champ->carry = 1;
	return (0);
}