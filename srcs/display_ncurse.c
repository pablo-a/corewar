/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ncurse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 18:18:34 by pabril            #+#    #+#             */
/*   Updated: 2016/06/18 12:42:14 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void draw_borders(WINDOW *screen)
{
	int x, y, i; 
	wattron(screen, COLOR_PAIR(9));
	getmaxyx(screen, y, x); // 4 corners 
	mvwprintw(screen, 0, 0, "+"); 
	mvwprintw(screen, y - 1, 0, "+"); 
	mvwprintw(screen, 0, x - 1, "+"); 
	mvwprintw(screen, y - 1, x - 1, "+"); // sides 
	for (i = 1; i < (y - 1); i++) 
	{ 
		mvwprintw(screen, i, 0, "|"); 
		mvwprintw(screen, i, x - 1, "|"); 
	} // top and bottom 
	for (i = 1; i < (x - 1); i++) 
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
		mvwprintw(win, *y, *x, "Champion %d : %s", -ID(node->champ),
											NAME(node->champ));
		mvwprintw(win, *y + 1, *x + 4, "Lives in current period : %d",
											node->champ->cpt_live[0]);
		mvwprintw(win, *y + 2, *x + 4, "Last live :               %d",
											node->champ->cpt_live[1]);
		*y += 4;
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
	wattron(win, COLOR_PAIR(4));
	y = 12;
	x = 7;
	mvwprintw(win, 10, x, "Current Cycle : %d", war->current_cycle);
	display_champs(war, win, &y, &x);
	y += 2;
	mvwprintw(win, y, x, "CYCLE_TO_DIE : %d", war->cycle_to_die);
	y += 3;
	mvwprintw(win, y, x, "CYCLE_DELTA : %d", CYCLE_DELTA);
	y += 3;
	mvwprintw(win, y, x, "NBR_LIVE : %d", NBR_LIVE);
	mvwprintw(win, y + 1, x + 4, "Current Lives : %d", war->current_live_nb);
	y += 4;
	mvwprintw(win, y, x, "MAX_CHECKS : %d", MAX_CHECKS);
	mvwprintw(win, y + 1, x + 4, "Current checks : %d", war->max_check);
	y += 4;
	mvwprintw(win, y, x, "GAME_SPEED : %dcycles/sec", war->ncurse->cycle_per_sec);
	y += 4;
	mvwprintw(win, y, x, " PAUSED : %d", PAUSE);
	wrefresh(win);
	wattroff(win, COLOR_PAIR(4));
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
		//put_good_color(win, war->ram2[index]);
		put_good_color(win, 2);
		mvwprintw(win, curr_y, curr_x, "%02.2x ", war->ram[index]);
		index++;
	}
	wrefresh(win);
	wattroff(win, COLOR_PAIR(2));
}

int		bad_size_window(int y, int x)
{
	wclear(stdscr);
	mvwprintw(stdscr, y / 2, (x - 10) / 2, "THE WINDOW IS TOO SMALL.");
	mvwprintw(stdscr, (y / 2) + 1, (x - 10) / 2, "RESIZE IT PLZ");
	getmaxyx(stdscr, y, x);
	while (y < MIN_HEIGHT || x < MIN_WIDTH)
	{
		wclear(stdscr);
		mvwprintw(stdscr, y / 2, (x - 20) / 2, "THE WINDOW IS TOO SMALL.");
		mvwprintw(stdscr, (y / 2) + 1, (x - 20) / 2, "RESIZE IT PLZ");
		mvwprintw(stdscr, (y / 2) + 2, (x - 20) / 2, "%d columns < %d columns", x, MIN_WIDTH);
		mvwprintw(stdscr, (y / 2) + 3, (x - 20) / 2, "%d rows < %d rows", y, MIN_HEIGHT);
		refresh();
		getmaxyx(stdscr, y, x);
	}
	wclear(stdscr);
	refresh();
	return (0);
}
