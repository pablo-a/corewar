/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_ncurse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 12:07:29 by pabril            #+#    #+#             */
/*   Updated: 2016/06/17 20:19:53 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		refresh_current_cycle(t_war *war)
{
	wattron(INFO_WINDOW, COLOR_PAIR(3));
	mvwprintw(INFO_WINDOW, 10, 7, "Current Cycle : %d", war->current_cycle);
	wrefresh(INFO_WINDOW);
	wattroff(INFO_WINDOW, COLOR_PAIR(3));
	usleep(war->ncurse->game_speed);
	return (1);
}

int		refresh_info_constants(t_war *war)
{
	int offset;

	wattron(INFO_WINDOW, COLOR_PAIR(3));
	offset = 12 + (war->args->nb_champ * 4) + 2;
	mvwprintw(INFO_WINDOW, offset, 7, "CYCLE_TO_DIE : %d", war->cycle_to_die);
	offset += 3;
	mvwprintw(INFO_WINDOW, offset, 7, "CYCLE_DELTA : %d", CYCLE_DELTA);
	offset += 3;
	mvwprintw(INFO_WINDOW, offset, 7, "NBR_LIVE : %d", NBR_LIVE);
	offset += 4;
	mvwprintw(INFO_WINDOW, offset, 7, "MAX_CHECKS : %d", MAX_CHECKS);
	offset++;
	mvwprintw(INFO_WINDOW, offset, 11, "Current checks : %d", war->max_check);
	offset += 3;
	mvwprintw(INFO_WINDOW, offset, 7, "GAME_SPEED : %dcycles/sec", war->ncurse->cycle_per_sec);
	offset += 4;
	mvwprintw(INFO_WINDOW, offset, 7, " PAUSED : %d", PAUSE);
	wattroff(INFO_WINDOW, COLOR_PAIR(3));
	wrefresh(INFO_WINDOW);
}

int		refresh_lives_info(t_war *war)
{
	t_node	*node;
	int		y;
	int		cpt;

	cpt = 0;
	node = war->pile_champ->first;
	y = 12;
	wattron(INFO_WINDOW, COLOR_PAIR(3));
	while (cpt < war->args->nb_champ)
	{
		mvwprintw(INFO_WINDOW, y + 1, 11, "Lives in current period : %d",
				node->champ->cpt_live[0]);
		mvwprintw(INFO_WINDOW, y + 2, 11, "Last live :               %d",
				node->champ->cpt_live[1]);
		y += 4;
		node = node->next;
		cpt++;
	}
	mvwprintw(INFO_WINDOW, y + 9, 11, "Current lives : %d", war->current_live_nb);
	wattroff(INFO_WINDOW, COLOR_PAIR(3));
	wrefresh(INFO_WINDOW);
}

int		calc_pos_in_ram(int *y, int *x, int size_window[2], int pos)
{
	pos = pos % MEM_SIZE;
	*x = (size_window[1] - ((BYTE_PER_LINE * 2) + (34 * SPACE_BT_BYTE) +
				SIZE_INFO + 6)) / 2;
	*x += ((pos % BYTE_PER_LINE) * (SPACE_BT_BYTE + 2));
	*y = (size_window[0] - (MEM_SIZE / BYTE_PER_LINE)) / 2;
	*y += (pos / BYTE_PER_LINE);
	return (0);
}

int		refresh_ram(t_war *war, int pos, int size, int color)
{
	int offset_y;
	int offset_x;
	int size_window[2];
	int cpt;

	wattron(MAIN_WINDOW, COLOR_PAIR(color));
	cpt = 0;
	getmaxyx(MAIN_WINDOW, size_window[0], size_window[1]);
	calc_pos_in_ram(&offset_y, &offset_x, size_window, pos);
	while (cpt < size)
	{
		mvwprintw(MAIN_WINDOW, offset_y, offset_x, "%02x", war->ram[pos]);
		cpt++;
		pos = (pos + 1) % MEM_SIZE;
		calc_pos_in_ram(&offset_y, &offset_x, size_window, pos);
	}
	wrefresh(MAIN_WINDOW);
	wattroff(MAIN_WINDOW, COLOR_PAIR(color));
	return (0);
}
