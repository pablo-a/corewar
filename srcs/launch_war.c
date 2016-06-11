/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_war.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 11:23:48 by pabril            #+#    #+#             */
/*   Updated: 2016/06/11 15:20:47 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libftprintf.h"

/* ------- OPTION -DUMP NB --------------------
**   arrete la partie au bout de NB cycles.
*/

int		dump_war(t_war *war)
{
	display_ram(war->ram);
	exit(0);
}

int		get_nbr_cycle(t_war *war, int pc)
{
	int result;
	int opcode;

	opcode = war->ram[pc];
	if (opcode < 0 || opcode > 16)
		error("bad OPCODE.");
	result = war->op_tab[opcode - 1].nb_cycle;//4 pour choper le nbr de cycles.
	return (result);
}

int		execute(t_war *war, int pc)
{
	int opcode;
	t_instruction_params params;

	opcode = war->ram[pc];
	if (opcode < 0 || opcode > 16)
		error("bad OPCODE.");

	war->op_tab[opcode - 1].associated_function(war, params);
	//adjust PC ;
	return (0);
}

/*
** ALLOWS PLAYERS TO EXECUTE HIS INSTRUCTION IF POSSIBLE. (CYCLE TURNS)
** IT IS USED EACH CYCLE.
*/

int		champ_action(t_war *war)
{
	t_node	*node;
	int		cycle_necessaires;

	node = war->pile_champ->last;// le dernier processus commence
	while (node)
	{
		cycle_necessaires = get_nbr_cycle(war, node->champ->pc);
		ft_printf("cycles_necessaire a \"%s\" : %d\ncompteur interne vaut : %d\n\n", NAME(node->champ), cycle_necessaires, node->champ->cpt_interne);
		if (node->champ->cpt_interne < cycle_necessaires)
			node->champ->cpt_interne++;
		else
		{
			execute(war, node->champ->pc);
			node->champ->cpt_interne = 1;
		}
		node = node->prev;
	}
	return (0);
}

/* MAIN FUNCTION WHICH MAKE CHAMPS PLAY DURING ONE TURN OF 'CYCLE_TO_DIE'.
** HANDLE THE 'CYCLE_TO_DIE' VARIABLE.
*/

int		launch_war(t_war *war)
{
	int cycle;

	war->current_live_nb = 0;
	cycle = 1;
	while (cycle < CYCLE_TO_DIE)
	{
		ft_printf("cycles numero  %d\n", cycle);
		// GERER TOUTES LES ACTIONS DES CHAMPIONS.
		champ_action(war);
		// CAS OU DUMP EST SPECIFIE
		if (war->args->dump > 0 && war->current_cycle == war->args->dump)
			dump_war(war);
		cycle++;
	}
	//PARTIE QUI GERE LE CYCLE TO DIE A DECREMENTER OU PAS.
	if (war->current_live_nb >= NBR_LIVE && (war->max_check = 0))
		war->cycle_to_die -= CYCLE_DELTA;
	else if (war->max_check >= MAX_CHECKS && (war->max_check = 0))
		war->cycle_to_die -= CYCLE_DELTA;
	else
		war->max_check++;
	war->current_cycle += cycle;
	return (0);
}
