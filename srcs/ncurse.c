/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 17:10:14 by pabril            #+#    #+#             */
/*   Updated: 2016/06/16 15:58:40 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void draw_borders(WINDOW *screen)
{
	int x, y, i; 
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

int		refresh_infos(WINDOW *win, t_war *war)
{
	int y;
	int x;

	wclear(win);
	draw_borders(win);
	y = 12;
	x = 3;
	mvwprintw(win, 10, 3, "Current Cycle : %d", war->current_cycle);
	display_champs(war, win, &y, &x);
	y += 2;
	mvwprintw(win, y, 3, "CYCLE_TO_DIE : %d", war->cycle_to_die);
	y += 3;
	mvwprintw(win, y, 3, "CYCLE_DELTA : %d", CYCLE_DELTA);
	y += 3;
	mvwprintw(win, y, 3, "NBR_LIVE : %d", NBR_LIVE);
	mvwprintw(win, y + 1, 7, "Current Lives : %d", war->current_live_nb);
	y += 4;
	mvwprintw(win, y, 3, "MAX_CHECKS : %d", MAX_CHECKS);
	mvwprintw(win, y + 1, 7, "Current checks : %d", war->max_check);
	y += 4;
	wrefresh(win);
	return (0);
}

void	refresh_main_content(WINDOW *win, t_war *war)
{
	int index;
	int curr_x;
	int curr_y;
	int size_x;
	int size_y;

	wclear(win);
	draw_borders(win);
	index = 0;
	curs_set(0);
	getmaxyx(win, size_y, size_x);
	curr_x = (size_x - ((BYTE_PER_LINE * 2) + (34 * SPACE_BT_BYTE) + SIZE_INFO + 6)) / 2;
	//ft_printf("size x = %d, curr_x = %d\n", size_x, curr_x);
	curr_y = (size_y - (MEM_SIZE / BYTE_PER_LINE)) / 2;
	while (index < MEM_SIZE)
	{
		if (index % BYTE_PER_LINE == BYTE_PER_LINE - 1)
		{
			mvwprintw(win, curr_y, curr_x, "%02.2x", war->ram[index]);
			curr_x = (size_x - ((BYTE_PER_LINE * 2) + (34 * SPACE_BT_BYTE) + SIZE_INFO + 6)) / 2;
			curr_y++;
		}
		else
		{
			mvwprintw(win, curr_y, curr_x, "%02.2x ", war->ram[index]);
			curr_x += 2 + SPACE_BT_BYTE;
		}
		index++;
	}
	wrefresh(win);
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

int		init_ncurse(t_war *war)
{
	WINDOW	*main_window;
	WINDOW	*info_window;
	int		screen_x;
	int		screen_y;
	int		tmp_x;
	int		tmp_y;

	initscr();
	getmaxyx(stdscr, screen_y, screen_x);
	main_window = newwin(screen_y, screen_x - SIZE_INFO, 0, 0);
	info_window = newwin(screen_y, SIZE_INFO, 0, screen_x - SIZE_INFO);
	//start_color();
	//init_pair(1, COLOR_BLUE, COLOR_RED);
	//wattron(main_window, COLOR_PAIR(1));
	//set_colors();
	if (screen_y < MIN_HEIGHT || screen_x < MIN_WIDTH)
		bad_size_window(screen_y, screen_x);
	refresh_main_content(main_window, war);
	refresh_infos(info_window, war);
	while (1)
	{
		getmaxyx(stdscr, tmp_y, tmp_x);
		if (tmp_y < MIN_HEIGHT || tmp_x < MIN_WIDTH)
			bad_size_window(tmp_y, tmp_x);
		else if (tmp_y != screen_y || tmp_x != screen_x)
		{
			screen_x = tmp_x;
			screen_y = tmp_y;
			wresize(main_window, screen_y, screen_x - SIZE_INFO);
			wresize(info_window, screen_y, SIZE_INFO);
			mvwin(info_window, 0, screen_x - SIZE_INFO);
			//wclear(stdscr);
			refresh_main_content(main_window, war);
			refresh_infos(info_window, war);
		}
		//mvwprintw(main_window, screen_y / 2, (screen_x - 20) / 2, "WE WANT RED");
		wrefresh(main_window);
		wrefresh(info_window);
	}
	//wattroff(main_window, COLOR_PAIR(1));
	return (0);
}
