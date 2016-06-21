/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_ncurse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 18:21:45 by pabril            #+#    #+#             */
/*   Updated: 2016/06/18 14:28:47 by pabril           ###   ########.fr       */
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
		endwin();
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

int		reset_colors(WINDOW *win)
{
	int i;

	i = 1;
	while (i < 11)
	{
		wattroff(win, COLOR_PAIR(i));
		i++;
	}
	return (0);
}
