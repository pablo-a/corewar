/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:48:59 by pabril            #+#    #+#             */
/*   Updated: 2016/06/14 02:02:58 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libftprintf.h"

static int	add_live(t_war *war, int id)
{
	t_node *node;

	node = war->pile_champ->first;
	while (node && node->champ->id != id)
		node = node->next;
	node->champ->cpt_live[0]++;
	node->champ->cpt_live[1] = war->current_cycle;
}

int		live(t_war *war, t_champ *champ)
{
	int id;

	war->current_live_nb++;
	id = get_value(war, champ->pc + 1, 4);
	if (id == champ->id)
	{
		champ->cpt_live[0]++;
		champ->cpt_live[1] = war->current_cycle;
		if (champ->father != NULL)
			champ->father->cpt_live[1] = war->current_cycle;
	}
	else
		add_live(war, id);
	champ->pc = calc_pc(champ->pc, 5);
	return (0);
}
