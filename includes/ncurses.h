/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:57:40 by pabril            #+#    #+#             */
/*   Updated: 2016/06/15 17:41:03 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef NCURSES_H
# define NCURSES_H

#include <ncurses.h>

typedef struct	s_infos
{
	int				width;
	int				height;
	int				start_x;
	int				start_y;
}				t_infos;

#endif
