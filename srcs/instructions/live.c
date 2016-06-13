/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:48:59 by pabril            #+#    #+#             */
/*   Updated: 2016/06/13 11:32:06 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libftprintf.h"

int		live(t_war *war, t_champ *champ)
{
	war->current_live_nb++;
	champ->cpt_live[0]++;
	champ->cpt_live[1] = war->current_cycle;
	champ->pc = calc_pc(champ->pc, 1);
	return (0);
}
