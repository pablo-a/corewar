/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:47:24 by pabril            #+#    #+#             */
/*   Updated: 2016/06/13 13:51:23 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libftprintf.h"

int		aff(t_war *war, t_champ *champ)
{
	int reg;
	int content;

	reg = war->ram[champ->pc + 2];
	if (reg < 1 || reg > 16)
	{
		champ->pc += 3;
		return (-1);
	}
	content = champ->reg_tab[reg - 1] % 256;
	champ->pc += 3;
	ft_putchar(content);
	return (0);
}
