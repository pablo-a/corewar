/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:48:59 by pabril            #+#    #+#             */
/*   Updated: 2016/06/24 04:51:03 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	add_live(t_war *war, int id)
{
	t_node *node;

	node = war->pile_champ->first;
	while (node && node->champ->id != id)
		node = node->next;
	if (!node)
		return (-1);
	node->champ->player->nbr_live++;
	node->champ->player->last_live = war->current_cycle;
	node->champ->player->current_nbr_live++;
	if (!war->args->ncurse && war->args->live)
		ft_printf("un processus dit que le joueur %d(%s) est en vie\n",
				-id, node->champ->header->prog_name);
	return (1);
}

int			live(t_war *war, t_champ *champ)
{
	int id;

	champ->tmp_pc = calc_pc(champ->pc, 1);
	war->current_live_nb++;
	id = get_value(war, champ->tmp_pc, 4);
	champ->cpt_live[0]++;
	champ->cpt_live[1] = war->current_cycle;
	if (id == champ->id)
	{
		champ->player->last_live = war->current_cycle;
		champ->player->nbr_live++;
		champ->player->current_nbr_live++;
		if (!war->args->ncurse && war->args->live)
			ft_printf("un processus dit que le joueur %d(%s) est en vie\n",
					-champ->id, champ->header->prog_name);
	}
	else
		add_live(war, id);
	refresh_pc(war, champ, champ->pc, champ->pc + 5);
	champ->pc = calc_pc(champ->pc, 5);
	return (0);
}
