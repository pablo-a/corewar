/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_war.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 11:23:48 by pabril            #+#    #+#             */
/*   Updated: 2016/06/27 15:38:43 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_proc_alive(t_war *war)
{
	t_node	*node;
	int		result;

	result = 0;
	node = war->pile_champ->first;
	while (node)
	{
		if (node->champ->is_dead == 0)
			result++;
		node = node->next;
	}
	return (result);
}

/*
** EXECUTE THE GOOD INSTRUCTION FROM A PROCESS WITH THE OPCODE
*/

int		execute(t_war *war, t_champ *champ)
{
	int ocpcode;

	ocpcode = champ->op_next;
	if (ocpcode < 1 || ocpcode > 16)
	{
		refresh_pc(war, champ, champ->pc, calc_pc(champ->pc, 1));
		champ->pc = calc_pc(champ->pc, 1);
	}
	else
		war->op_tab[ocpcode - 1].associated_function(war, champ);
	champ->op_update = 1;
	return (0);
}

/*
** ALLOWS PLAYERS TO EXECUTE HIS INSTRUCTION IF POSSIBLE. (CYCLE TURNS)
** IT IS USED EACH CYCLE.
*/

int		champ_action(t_war *war)
{
	t_node	*node;

	copy_ram(war->ram2, war->ram);
	node = war->pile_champ->last;
	while (node)
	{
		if (!node->champ->is_dead && node->champ->op_update)
		{
			node->champ->op_next = war->ram[node->champ->pc];
			node->champ->op_cycles = get_nbr_cycle(war, node->champ->pc);
			node->champ->op_update = 0;
			node->champ->cpt_interne = 1;
		}
		node = node->prev;
	}
	node = war->pile_champ->last;
	while (node)
	{
		if (!node->champ->is_dead)
		{
			if (node->champ->cpt_interne < node->champ->op_cycles)
				node->champ->cpt_interne++;
			else
				execute(war, node->champ);
		}
		node = node->prev;
	}
	copy_ram(war->ram, war->ram2);
	return (0);
}

/*
** MAIN FUNCTION WHICH MAKE CHAMPS PLAY DURING ONE TURN OF 'CYCLE_TO_DIE'.
** HANDLE THE 'CYCLE_TO_DIE' VARIABLE.
*/

int		launch_war(t_war *war)
{
	int cycle;

	cycle = -1;
	war->max_check++;
	war->current_live_nb = 0;
	while (++cycle < war->cycle_to_die && ++war->current_cycle)
	{
		ft_printf("It is now cycle %d\n", war->current_cycle);
		champ_action(war);
		if (war->args->dump > 0 && (war->current_cycle) == war->args->dump)
			dump_war(war);
		if (war->args->ncurse == 1)
		{
			check_size_window(war);
			refresh_info_constants(war);
			event(war, 1);
			refresh_current_cycle(war);
			refresh_lives_info(war);
		}
	}
	handle_cycle_to_die(war);
	find_dead_champs(war);
	reset_champ_live(war);
	return (0);
}
