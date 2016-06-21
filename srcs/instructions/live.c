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

static int	add_live(t_war *war, int id)
{
	//TODO Find logic on what to do when the live is not by the process :

	t_node *node;

	node = war->pile_champ->first;
	while (node && node->champ->id != id)
		node = node->next;
	if (!node)
		return (-1);

	//TODO This should be the parent for the live :
	node->champ->cpt_live[0]++;
	node->champ->cpt_live[1] = war->current_cycle;
	return (1);
}

int		live(t_war *war, t_champ *champ)
{
	//TODO Print message to say champ is alive :
	int id;

	champ->tmp_pc = calc_pc(champ->pc, 1);
	war->current_live_nb++;
	id = get_value(war, champ->tmp_pc, 4);
	if (id == champ->id)
	{
		champ->cpt_live[0]++;
		champ->cpt_live[1] = war->current_cycle;
		if (champ->father != NULL)
			champ->father->cpt_live[1] = war->current_cycle;
	}
	else
		add_live(war, id);

//	ft_printf("Live at cycle %d\n",war->current_cycle);

	champ->pc = calc_pc(champ->pc, 5);
	return (0);
}
