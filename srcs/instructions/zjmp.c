/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:50:21 by pabril            #+#    #+#             */
/*   Updated: 2016/06/11 13:50:25 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libftprintf.h"

int		zjmp(t_war *war, t_champ *champ)
{
	short int i;

	if (champ->carry == 1)
	{
		i = (short int) (get_value(war, champ->pc + 1, 2) % MEM_SIZE);
		champ->pc = champ->pc + i;
		if (champ->pc < 0)
			champ->pc = (MEM_SIZE) + champ->pc;
		return (0);
	}
	champ->pc++;
	return (-1);
}
