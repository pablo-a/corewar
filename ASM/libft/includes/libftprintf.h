/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:23:10 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 15:26:12 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <limits.h>
# include <wchar.h>
# define CONVERSIONS "sSpdDioOuUxXcC"
# define OPTIONS "#0-+ 123456789.hljz"

typedef struct		s_flag
{
	BOOL sharp;
	BOOL zero;
	BOOL plus;
	BOOL minus;
	BOOL space;
}					t_flag;

typedef struct		s_lmod
{
	BOOL hh;
	BOOL h;
	BOOL l;
	BOOL ll;
	BOOL j;
	BOOL z;
}					t_lmod;

typedef struct		s_info
{
	char	*format;
	size_t	cursor;
	char	*str;
	int		ret;
	t_flag	*flag;
	t_lmod	*lmod;
	char	c;
	size_t	prec;
	BOOL	isprec;
	size_t	field;
	char	*tmp;
	size_t	oct;
	size_t	oct2;
}					t_info;

typedef struct		s_conv
{
	char		c;
	void		(*f)(t_info *info, va_list ap);
}					t_conv;

int					ft_printf(const char *format, ...);
t_info				*info_utils(t_info *info, char *format);
void				build_info(t_info *info, va_list ap);

void				extract_nb_from_str(t_info *info, size_t *save);
void				print_buffer(t_info *info);
char				*prec_nb(t_info *info, char *str);
void				free_info(t_info *info);

void				conv_arg(char c, t_info *info, va_list ap);
void				conv_s(t_info *info, va_list ap);
void				conv_ss(t_info *info, va_list ap);
void				conv_i(t_info *info, va_list ap);
void				conv_d(t_info *info, va_list ap);
void				conv_dd(t_info *info, va_list ap);
void				conv_c(t_info *info, va_list ap);
void				conv_cc(t_info *info, va_list ap);
void				conv_u(t_info *info, va_list ap);
void				conv_uu(t_info *info, va_list ap);
void				conv_p(t_info *info, va_list ap);
void				conv_x(t_info *info, va_list ap);
void				conv_xx(t_info *info, va_list ap);
void				conv_o(t_info *info, va_list ap);
void				conv_oo(t_info *info, va_list ap);

void				transform_str(t_info *info, char *str);
void				transform_char(t_info *info, size_t oct);

#endif
