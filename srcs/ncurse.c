/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 17:10:14 by pabril            #+#    #+#             */
/*   Updated: 2016/06/15 18:21:06 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

init_ncurse(t_war *war)
{
	WINDOW	*main_window;
	int		screen_x;
	int		screen_y;

	getmaxyx(stdscr, y, x);
	initscr();
	main_window = newwin(screen_y, screen_x, 0, 0);
	box(main_window, 0, 0);
	wrefresh(main_window);
	endwin();

}
