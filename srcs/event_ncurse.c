/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_ncurse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 18:21:45 by pabril            #+#    #+#             */
/*   Updated: 2016/06/17 20:10:28 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		event(t_war *war, no_delay)
{
	int ch;

	if (no_delay && PAUSE == 0)
		nodelay(EVENT_WINDOW, TRUE);
	else
		nodelay(EVENT_WINDOW, FALSE);
	ch = wgetch(EVENT_WINDOW);
	if (ch == 27)// ESC
	{
		clear();
		refresh();
		exit(0);
	}
	else if (ch == 32 && PAUSE == 1)
		PAUSE = 0;
	else if (ch == 32 && PAUSE == 0)
	{
		PAUSE = 1;
		refresh_info_constants(war);
		while (PAUSE == 1)
		{
			event(war, 0);
			check_size_window(war);
		}
	}
	else if (ch == 43 && war->ncurse->cycle_per_sec < 500)// '+'
	{
			war->ncurse->cycle_per_sec += 10;
			war->ncurse->game_speed = (1000000 / war->ncurse->cycle_per_sec);
	}
	else if (ch == 45 && war->ncurse->game_speed < 50000)// '-'
	{
			war->ncurse->cycle_per_sec -= 10;
			war->ncurse->game_speed = (1000000 / war->ncurse->cycle_per_sec);
	}
	refresh_info_constants(war);
	return (0);
}
