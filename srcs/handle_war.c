/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_war.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 19:20:44 by pabril            #+#    #+#             */
/*   Updated: 2016/06/24 19:24:21 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		reset_champ_live(t_war *war)
{
	t_node *node;

	node = war->pile_champ->first;
	while (node)
	{
		node->champ->cpt_live[0] = 0;
		node->champ->player->current_nbr_live = 0;
		node = node->next;
	}
	return (0);
}

int		find_dead_champs(t_war *war)
{
	t_node	*node;

	node = war->pile_champ->first;
	while (node)
	{
		if (!node->champ->is_dead && node->champ->cpt_live[0] == 0)
		{

//			ft_printf("DEAD %d at cycle %d last live %d (CTD : %d)\n", node->champ->id_process, war->current_cycle, war->current_cycle - node->champ->cpt_live[1], war->cycle_to_die);
			node->champ->is_dead = 1;
			erase_pc(war, node->champ, node->champ->pc);
		}
		node = node->next;
	}
	return (0);
}

/*
** ------- OPTION -DUMP NB --------------------
**   arrete la partie au bout de NB cycles.
*/

int		dump_war(t_war *war)
{
	display_ram(war->ram, war->ram_info);
	exit(0);
}

int		get_nbr_cycle(t_war *war, int pc)
{
	int result;
	int ocpcode;

	ocpcode = war->ram[pc];
	if (ocpcode < 1 || ocpcode > 16)
	{
		result = 1;
		return (result);
	}
	result = war->op_tab[ocpcode - 1].nb_cycle;
	return (result);
}

int		handle_cycle_to_die(t_war *war)
{
	if (war->current_live_nb >= NBR_LIVE)
	{
		war->max_check = 0;
		war->cycle_to_die = war->cycle_to_die - CYCLE_DELTA;
	}
	else if (war->max_check >= MAX_CHECKS)
	{
		war->max_check = 0;
		war->cycle_to_die = war->cycle_to_die - CYCLE_DELTA;
	}
	return (0);
}
