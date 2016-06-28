/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 19:35:49 by pabril            #+#    #+#             */
/*   Updated: 2016/06/23 23:51:39 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	reg(t_war *war, t_champ *champ, t_return *ret, int reg_value)
{
	ret->value = war->ram[champ->tmp_pc];
	if (ret->value > 0 && ret->value < 17)
	{
		ret->error = 0;
		if (reg_value)
			ret->value = champ->reg_tab[ret->value - 1];
	}
	champ->tmp_pc = calc_pc(champ->tmp_pc, 1);
}

static void	direct(t_war *war, t_champ *champ, t_return *ret, int is_index)
{
	int bits;

	ret->error = 0;
	bits = 4;
	if (is_index)
		bits = 2;
	ret->value = get_value(war, champ->tmp_pc, bits);
	champ->tmp_pc = calc_pc(champ->tmp_pc, bits);
}

static void	indirect(t_war *war, t_champ *champ, t_return *ret, int add_value)
{
	ret->error = 0;
	ret->value = get_value(war, champ->tmp_pc, 2) % IDX_MOD;
	if (add_value)
		ret->value = get_value(war, calc_pc(champ->pc, ret->value), 4);
	champ->tmp_pc = calc_pc(champ->tmp_pc, 2);
}

t_return	get_param(t_war *war, t_params params, int param_code,
		t_champ *champ)
{
	t_return	ret;
	int			nb_oct;

	ret.error = 1;
	ret.value = 0;
	if (param_code == params.reg)
		reg(war, champ, &ret, params.opt.reg_value);
	else if (param_code == params.direct)
		direct(war, champ, &ret, params.opt.is_index);
	else if (param_code == params.indirect)
		indirect(war, champ, &ret, params.opt.add_value);
	else if (ret.error)
	{
		if (param_code == DIR_CODE && !params.opt.is_index)
			nb_oct = 4;
		else if (param_code == DIR_CODE && params.opt.is_index)
			nb_oct = 2;
		else if (param_code == REG_CODE)
			nb_oct = 1;
		else if (param_code == IND_CODE)
			nb_oct = 2;
		else
			nb_oct = 0;
		champ->tmp_pc = calc_pc(champ->tmp_pc, nb_oct);
	}
	return (ret);
}
