//
// Created by mcotfas on 15/06/16.
//

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

	if (value > 32768)
	{
		ft_printf("value : %d\n", value);
		value = value - 65536;
	}

	value = value % IDX_MOD;

	ft_printf("value : %d\n", value);


	ret->error = 0;
	ret->value = get_value(war, calc_pc(champ->pc, value), 4);



	ft_printf("indirect value : %d\n", ret->value);

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
