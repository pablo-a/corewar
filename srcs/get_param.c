/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 19:35:49 by pabril            #+#    #+#             */
/*   Updated: 2016/06/18 22:01:29 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void reg(t_war *war, t_champ *champ, t_return *ret, int reg_value)
{
	ret->error = 1;
	ret->value = war->ram[champ->tmp_pc];
	if (ret->value > 0 && ret->value < 17)
	{
		ret->error = 0;
		if (reg_value)
			ret->value = champ->reg_tab[ret->value - 1];
		champ->tmp_pc = calc_pc(champ->tmp_pc, 1);
	}
}

static void direct(t_war *war, t_champ *champ, t_return *ret, int is_index)
{
	int bits;

	bits = 4;
	if (is_index)
		bits = 2;
	ret->error = 0;
	ret->value = get_value(war, champ->tmp_pc, bits);
	champ->tmp_pc = calc_pc(champ->tmp_pc, bits);
}

static void indirect(t_war *war, t_champ *champ, t_return *ret)
{

	int value;

	//obtenir la valeur saisie pour indirect :
	value  = get_value(war, champ->tmp_pc, 2);

	value = value % IDX_MOD;

	ret->error = 0;
	ret->value = get_value(war, calc_pc(champ->pc, value), 4);

	champ->tmp_pc = calc_pc(champ->tmp_pc, 2);
}

t_return get_param(t_war *war, t_params params, int param_code, t_champ *champ)
{
	t_return ret;

	ret.error = 1;
	ret.value = 0;
	if (param_code == params.reg)
		reg(war, champ, &ret, params.opt.reg_value);
	else if (param_code == params.direct)
		direct(war, champ, &ret, params.opt.is_index);
	else if (param_code == params.indirect)
		indirect(war, champ, &ret);
	return (ret);
}
