/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 15:31:03 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/18 17:47:41 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include <stdlib.h>
# include "libft/includes/libft.h"
# include "op.h"

#include <stdio.h>

typedef struct	s_strct
{
	struct s_str		*file;
	char				**tab_command;
	char				*name;
	char				*comment;
	int					l;
	int					c;
	struct s_byteline	*bytelines;
}				t_strct;

typedef struct	s_str
{
	struct s_str	*next;
	char			*str;
}				t_str;

typedef struct	s_byteline
{
	struct s_byteline	*next;
	int					label;
	char				*name;
	int					len;
	char				*byte_line;
}				t_byteline;

/*
**	main.c
*/
int				main(int argc, char **argv);
void			asm_error(char *str);

/*
** asm_parse_file.c
*/
t_strct			*asm_init_strct(void);
t_str			*asm_lst_append(t_str *lst, char *str);
t_str			*asm_get_file(char *name);
int				asm_parse_file(char *name);

/*
** asm_check_file.c
*/
int				asm_check_file(t_strct *strct);

/*
** asm_check_header.c
*/
t_str			*asm_check_header(t_str *lst, t_strct *strct);

/*
** asm_check_label.c
*/
t_str			*asm_check_label(t_str *lst, t_strct *strct);

/*
** asm_strsplit.c
*/
char			**asm_strsplit(char const *s);

/*
** asm_util.c
*/
t_str			*asm_lst_browse(t_str *lst, int *l, int d);
int				asm_str_browse(char *str);
void			*asm_lc_error(t_strct *strct);
char			*asm_join(char *str1, char *str2);
int				asm_intlen(int i);

/*
** asm_check_command.c
*/
void			asm_and(char **array, t_strct *strct, t_byteline *new, int len);
void			asm_ldi(char **array, t_strct *strct, t_byteline *new, int len);
void			asm_sti(char **array, t_strct *strct, t_byteline *new, int len);
void			asm_aff(char **array, t_strct *strct, t_byteline *new, int len);
int				asm_check_command(int i, char *str, t_strct *strct);

/*
** asm_check_command.c
*/
void			asm_live(char **array, t_strct *strct, t_byteline *new, int l);
void			asm_zjmp(char **array, t_strct *strct, t_byteline *new, int l);
void			asm_ld(char **array, t_strct *strct, t_byteline *new, int len);
void			asm_st(char **array, t_strct *strct, t_byteline *new, int len);
void			asm_add(char **array, t_strct *strct, t_byteline *new, int l);

/*
** asm_check_arg.c
*/
int				asm_is_ind(char *str, t_byteline *new);
int				asm_is_dir(char *str, t_byteline *new, int len);
int				asm_is_reg(char *str, t_byteline *new);
void			asm_save_arg(char *str, t_strct *strct, char *name, int *len, int c);
void			asm_save_arg_finish(char *str, char *ptr, t_strct *strct, char *name, int *len, int c);

/*
**  asm_parse_command.c
*/
int				asm_count_arg(char *arg);
int				asm_find_opc(char **arg, int l);
int				asm_parse_command(t_strct *strct);

/*
** asm_find_command.c
*/
int				asm_find_command(char *command, t_strct *strct);
int				asm_label_size(char *command);

/*
** asm_encode.c
*/
int				asm_find_label(t_strct *strct, t_byteline *ptr, char *name);
int				asm_encode(char *byte_line, char *nbr, int l_size, int c);
int				asm_encode_label(char *byte_line, int n, int l_size, int c);

/*
** asm_create_file.c
*/
int				asm_write_file(t_strct *strct, char *name);

#endif
