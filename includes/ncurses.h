/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:57:40 by pabril            #+#    #+#             */
/*   Updated: 2016/06/15 17:01:52 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef NCURSES_H
# define NCURSES_H

typedef struct	s_border
{
	chtype ls;
	chtype rs;
	chtype ts;
	chtype bs;
	chtype ls;
	chtype tl;
	chtype tr;
	chtype bl;
	chtype br;
}				t_border;

typedef struct	s_window
{
	int				width;
	int				height;
	int				start_x;
	int				start_y;
	struct s_border	border;
}				t_window;

#endif
