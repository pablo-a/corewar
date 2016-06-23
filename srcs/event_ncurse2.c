/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_ncurse2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 19:53:40 by pabril            #+#    #+#             */
/*   Updated: 2016/06/23 20:01:21 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		event_ncurse2(t_war *war, int ch)
{
	if (ch == 32 && PAUSE == 1)
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
	else if (ch == 43 && war->ncurse->cycle_per_sec < 700)
	{
		war->ncurse->cycle_per_sec += 10;
		war->ncurse->game_speed = (1000000 / war->ncurse->cycle_per_sec);
	}
	else if (ch == 45 && war->ncurse->cycle_per_sec > 10)
	{
		war->ncurse->cycle_per_sec -= 10;
		war->ncurse->game_speed = (1000000 / war->ncurse->cycle_per_sec);
	}
	return (0);
}
