/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 16:29:16 by pabril            #+#    #+#             */
/*   Updated: 2016/06/23 16:29:44 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_param_opt		def_opt(int is_index, int reg_value, int add_value)
{
	t_param_opt opt;

	opt.is_index = is_index;
	opt.reg_value = reg_value;
	opt.add_value = add_value;
	return (opt);
}
