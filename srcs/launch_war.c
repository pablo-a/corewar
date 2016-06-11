/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_war.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 11:23:48 by pabril            #+#    #+#             */
/*   Updated: 2016/06/11 12:40:40 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libftprintf.h"

/* RETURN 0 IF NO PLAYER ARE ALIVE AT THE END OF 'CYCLE_TO_DIE' CYCLES.
** RETURN 1 IF WAR NOT OVER YET.
*/
int		its_over(t_war *war)
{
	return (1);
}

int		dump_war(t_war *war)
{
	exit(0);
}

/* ALLOWS PLAYERS TO EXECUTE HIS INSTRUCTION IF POSSIBLE. (CYCLE TURNS)
** IT IS USED EACH CYCLE.
*/

int		champ_action(t_war *war, int cycle)
{
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
		// CAS OU DUMP EST SPECIFIE
		if (war->args->dump > 0 && war->current_cycle == war->args->dump)
			dump_war(war);
		// GERER TOUTES LES ACTIONS DES CHAMPIONS.
		champ_action(war, cycle);
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
