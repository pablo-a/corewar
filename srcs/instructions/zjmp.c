/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:50:21 by pabril            #+#    #+#             */
/*   Updated: 2016/06/13 23:06:06 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		zjmp(t_war *war, t_champ *champ)
{
	if (champ->carry == 1)
	{
		champ->pc = calc_pc(champ->pc, get_value(war, champ->pc + 1, 2));
		return (0);
	}
	champ->pc = calc_pc(champ->pc, 3);
	return (-1);
}
