/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:50:21 by pabril            #+#    #+#             */
/*   Updated: 2016/06/23 17:22:07 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		zjmp(t_war *war, t_champ *champ)
{
	if (champ->carry == 1)
	{
		refresh_pc(war, champ, champ->pc, calc_pc(champ->pc,
					get_value(war, champ->pc + 1, 2)));
		champ->pc = calc_pc(champ->pc, get_value(war, champ->pc + 1, 2));
		return (0);
	}
	refresh_pc(war, champ, champ->pc, champ->pc + 3);
	champ->pc = calc_pc(champ->pc, 3);
	return (-1);
}
