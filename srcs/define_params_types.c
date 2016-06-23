/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_params_types.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 16:30:03 by pabril            #+#    #+#             */
/*   Updated: 2016/06/23 16:30:55 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_params	define_params_types(int type1, int type2, int type3,
		t_param_opt opt)
{
	t_params params;

	params.reg = type1;
	params.direct = type2;
	params.indirect = type3;
	params.opt = opt;
	return (params);
}
