/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:46:33 by pabril            #+#    #+#             */
/*   Updated: 2016/06/11 15:56:33 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libftprintf.h"

int		add(t_war *war, t_champ *champ)
{
	int r1;
	int r2;
	int r3;

	r1 = war->ram[champ->pc + 2];
	r2 = war->ram[champ->pc + 3];
	champ->reg_tab[champ->px + 4] = r1 + r2;
	return (0);
}
