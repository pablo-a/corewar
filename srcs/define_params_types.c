//
// Created by mcotfas on 15/06/16.
//

#include "corewar.h"

t_params define_params_types(int type1, int type2, int type3, int is_index)
{
	t_params params;

	params.reg = type1;
	params.direct = type2;
	params.indirect = type3;
	params.is_index = is_index;
	return (params);
}
