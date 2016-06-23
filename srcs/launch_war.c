/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_war.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 11:23:48 by pabril            #+#    #+#             */
/*   Updated: 2016/06/23 16:09:19 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libftprintf.h"

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
	t_node *node;
	int i = 1;

	node = war->pile_champ->first;
	while (node)
	{
		if (!node->champ->is_dead && node->champ->cpt_live[0] == 0)
		{
			node->champ->is_dead = 1;
			erase_pc(war, node->champ, node->champ->pc);
		}
		node = node->next;
		i++;
	}
	return (0);
}

/* ------- OPTION -DUMP NB --------------------
**   arrete la partie au bout de NB cycles.
*/

int		dump_war(t_war *war)
{
	display_ram(war->ram, war->ram_info);
	display_ram_info(war->ram_info);
	exit(0);
}

int		get_nbr_cycle(t_war *war, int pc)
{
	int result;
	int ocpode;

	ocpode = war->ram[pc];
	if (ocpode < 1 || ocpode > 16)
	{
		result = 1;
		return (result);
	}
	result = war->op_tab[ocpode - 1].nb_cycle;
	return (result);
}

int		execute(t_war *war, t_champ *champ)
{
	int ocpcode;

	ocpcode = war->ram[champ->pc];
	//TODO How increment when op code wrong ?
	if (ocpcode < 1 || ocpcode > 16)
	{
		refresh_pc(war, champ, champ->pc, calc_pc(champ->pc, 1));
		champ->pc = calc_pc(champ->pc, 1);
	}
	else
		war->op_tab[ocpcode - 1].associated_function(war, champ);
	champ->cpt_interne = 1;
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
		if (!node->champ->is_dead)
		{
			cycle_necessaires = get_nbr_cycle(war, node->champ->pc);
			if (node->champ->cpt_interne < cycle_necessaires)
				node->champ->cpt_interne++;
			else
				execute(war, node->champ);
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

	cycle = -1;
	//TODO Move this into another fct :
	war->max_check++;
//	ft_printf("cycles numero  %d\n", war->current_cycle);
	//ft_printf("check = %d\n", war->max_check);
	if (war->current_live_nb >= NBR_LIVE)
	{
		war->max_check = 0;
		war->cycle_to_die = war->cycle_to_die - CYCLE_DELTA;;
	}
	else if (war->max_check >= MAX_CHECKS)
	{
		war->max_check = 0;
		war->cycle_to_die = war->cycle_to_die - CYCLE_DELTA;
	}
	war->current_live_nb = 0;
	while (++cycle < war->cycle_to_die && ++war->current_cycle)
	{
		//++war->current_cycle;
//		ft_printf("cycles numero  %d\n", war->current_cycle);
		// GERER TOUTES LES ACTIONS DES CHAMPIONS.
		champ_action(war);
		// CAS OU DUMP EST SPECIFIE
		if (war->args->dump > 0 && (war->current_cycle) == war->args->dump)
			dump_war(war);
		if (war->args->ncurse == 1)
		{
			check_size_window(war);
			refresh_info_constants(war);// REFRESH LES CONSTANTES DE JEU
			//refresh_ram(war, 4000 + cycle, 4, 9);
			event(war, 1);
			refresh_current_cycle(war);// REFRESH LE COMPTEUR DE CYCLE
			refresh_lives_info(war);// REFRESH TOUTES LES VARIABLES LIVES
		}
	}
	//refresh_current_cycle(war);// REFRESH LE COMPTEUR DE CYCLE
	find_dead_champs(war);
	reset_champ_live(war);
	return (0);
}
