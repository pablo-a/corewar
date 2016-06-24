/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 17:10:14 by pabril            #+#    #+#             */
/*   Updated: 2016/06/24 02:08:35 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** COLORS FROM 1 TO 4 = COLORS FOR CHAMPS
** COLORS FROM 5 TO 9 = COLORS FOR CHAMP PC
** COLOR 9 = BORDER COLOR
** COLOR 10 = DEFAULT COLOR
*/

int		set_colors(void)
{
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_BLUE);
	init_pair(6, COLOR_BLACK, COLOR_GREEN);
	init_pair(7, COLOR_BLACK, COLOR_RED);
	init_pair(8, COLOR_BLACK, COLOR_CYAN);
	init_pair(9, COLOR_BLUE, COLOR_RED);
	init_pair(10, COLOR_WHITE, COLOR_BLACK);
	return (0);
}

int		put_good_color(WINDOW *win, int color)
{
	wattron(win, COLOR_PAIR(color));
	return (0);
}

int		init_ncurse_struct(t_war *war)
{
	t_ncurse	*ncurse;
	int			screen_x;
	int			screen_y;

	initscr();
	start_color();
	ncurse = (t_ncurse *)malloc(sizeof(t_ncurse));
	getmaxyx(stdscr, screen_y, screen_x);
	ncurse->main_window = newwin(screen_y, screen_x - SIZE_INFO, 0, 0);
	ncurse->info_window = newwin(screen_y, SIZE_INFO, 0, screen_x - SIZE_INFO);
	ncurse->event_window = newwin(1, 1, 1, 1);
	ncurse->game_speed = GAME_SPEED;
	ncurse->cycle_per_sec = 100;
	ncurse->size_window[0] = screen_y;
	ncurse->size_window[1] = screen_x;
	ncurse->pause = 1;
	war->ncurse = ncurse;
	noecho();
	return (0);
}

int		check_size_window(t_war *war)
{
	int		tmp_y;
	int		tmp_x;

	getmaxyx(stdscr, tmp_y, tmp_x);
	if (tmp_y < MIN_HEIGHT || tmp_x < MIN_WIDTH)
		bad_size_window(tmp_y, tmp_x);
	else if (tmp_y != SCREEN_Y || tmp_x != SCREEN_X)
	{
		SCREEN_X = tmp_x;
		SCREEN_Y = tmp_y;
		wresize(MAIN_WINDOW, SCREEN_Y, SCREEN_X - SIZE_INFO);
		wresize(INFO_WINDOW, SCREEN_Y, SIZE_INFO);
		mvwin(INFO_WINDOW, 0, SCREEN_X - SIZE_INFO);
		display_main_content(MAIN_WINDOW, war);
		display_infos(INFO_WINDOW, war);
	}
	return (0);
}

int		init_ncurse(t_war *war)
{
	int ch;

	ch = 0;
	init_ncurse_struct(war);
	keypad(EVENT_WINDOW, TRUE);
	curs_set(0);
	set_colors();
	check_size_window(war);
	display_main_content(MAIN_WINDOW, war);
	display_infos(INFO_WINDOW, war);
	while (PAUSE == 1)
		event(war, 0);
	while (war->current_live_nb > 0)
		launch_war(war);
	who_won(war);
	nodelay(EVENT_WINDOW, FALSE);
	while (ch != 27)
		ch = wgetch(EVENT_WINDOW);
	event(war, 0);
	clear();
	refresh();
	endwin();
	return (0);
}
