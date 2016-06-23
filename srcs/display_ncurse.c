/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ncurse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 18:18:34 by pabril            #+#    #+#             */
/*   Updated: 2016/06/23 19:41:45 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	draw_borders(WINDOW *screen)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	wattron(screen, COLOR_PAIR(9));
	getmaxyx(screen, y, x);
	mvwprintw(screen, 0, 0, "+");
	mvwprintw(screen, y - 1, 0, "+");
	mvwprintw(screen, 0, x - 1, "+");
	mvwprintw(screen, y - 1, x - 1, "+");
	while (++i < (y - 1))
	{
		mvwprintw(screen, i, 0, "|");
		mvwprintw(screen, i, x - 1, "|");
	}
	i = 0;
	while (++i < (x - 1))
	{
		mvwprintw(screen, 0, i, "-");
		mvwprintw(screen, y - 1, i, "-");
	}
	wrefresh(screen);
	wattroff(screen, COLOR_PAIR(9));
}

int		display_champs(t_war *war, WINDOW *win, int *y, int *x)
{
	int		cpt;
	t_node	*node;

	cpt = 0;
	node = war->pile_champ->first;
	while (cpt < war->args->nb_champ)
	{
		put_good_color(win, -node->champ->id);
		mvwprintw(win, *y, *x, "Champion %d : %s", -ID(node->champ),
											NAME(node->champ));
		reset_colors(win);
		mvwprintw(win, *y + 1, *x + 4, "Total lives since begin : %d   ",
									node->champ->player->nbr_live);
		mvwprintw(win, *y + 2, *x + 4, "current live :            %d   ",
									node->champ->player->current_nbr_live);
		mvwprintw(win, *y + 3, *x + 4, "Last live :               %d   ",
											node->champ->player->last_live);
		*y += 5;
		cpt++;
		node = node->next;
	}
	return (0);
}

void	display_infos(WINDOW *win, t_war *war)
{
	int y;
	int x;

	wclear(win);
	draw_borders(win);
	y = 12;
	x = 7;
	put_good_color(win, 3);
	wattron(win, A_BOLD);
	mvwprintw(win, 10, x, "Current Cycle : %d", war->current_cycle);
	wattroff(win, A_BOLD);
	reset_colors(win);
	display_champs(war, win, &y, &x);
	mvwprintw(win, y + 2, x, "CYCLE_TO_DIE : %d", war->cycle_to_die);
	mvwprintw(win, y + 5, x, "CYCLE_DELTA : %d", CYCLE_DELTA);
	mvwprintw(win, y + 8, x, "NBR_LIVE : %d", NBR_LIVE);
	mvwprintw(win, y + 9, x + 4, "Current Lives : %d", war->current_live_nb);
	mvwprintw(win, y + 12, x, "MAX_CHECKS : %d", MAX_CHECKS);
	mvwprintw(win, y + 13, x + 4, "Current checks : %d", war->max_check);
	mvwprintw(win, y + 16, x, "GAME_SPEED : %d cycles/sec",
				war->ncurse->cycle_per_sec);
	mvwprintw(win, y + 20, x, " PAUSED : %d", PAUSE);
	wrefresh(win);
}

void	display_pc(t_war *war)
{
	int		cpt;
	t_node	*node;

	cpt = 0;
	node = war->pile_champ->first;
	while (cpt < war->args->nb_champ)
	{
		refresh_ram(war, node->champ->pc, 1, -node->champ->id + 4);
		cpt++;
		node = node->next;
	}
}

void	display_main_content(WINDOW *win, t_war *war)
{
	int		index;
	int		curr_x;
	int		curr_y;
	int		size_window[2];

	wclear(win);
	draw_borders(win);
	index = 0;
	getmaxyx(win, size_window[0], size_window[1]);
	while (index < MEM_SIZE)
	{
		calc_pos_in_ram(&curr_y, &curr_x, size_window, index);
		put_good_color(win, war->ram_info[index]);
		mvwprintw(win, curr_y, curr_x, "%02.2x ", war->ram[index]);
		reset_colors(win);
		index++;
	}
	display_pc(war);
	wrefresh(win);
}
