/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:46:33 by pabril            #+#    #+#             */
/*   Updated: 2016/06/11 17:08:42 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libftprintf.h"

int		add(t_war *war, t_champ *champ)
{
	int r1;
	int r2;
	int r3;

	r1 = war->ram[champ->pc + 2] - 1;
	r2 = war->ram[champ->pc + 3] - 1;
	r3 = war->ram[champ->pc + 4] - 1;
	if (r1 > 15 || r1 < 0 || r2 < 0 || r2 > 15 || r3 > 15 || r3 < 0)
	{
		champ->carry = 0;
		champ->pc += 5;
		return (-1);
	}
	champ->reg_tab[r3] = champ->reg_tab[r1] + champ->reg_tab[r2];
	champ->carry = 1;
	champ->pc += 5;
	ft_printf("%d + %d gives %d", champ->reg_tab[r1], champ->reg_tab[r2], champ->reg_tab[r3]);
	return (0);
}
