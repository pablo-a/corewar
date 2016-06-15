/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 15:31:03 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/15 17:44:53 by vbarrete         ###   ########.fr       */
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

//	header_t	*header;
//	char		*program;
}				t_strct;

typedef struct	s_str
{
	struct s_str	*next;
	char			*str;
}				t_str;

typedef struct s_byteline
{
	struct s_byteline	*next;
	int					label; //(0 | 1)
	char				*name;
	int					size;


	char				*byte_line;
}					t_byteline;

/*
typedef struct	s_label
{
	struct s_label	*next;
	char			*name;
	int				i;
}				t_label;

typedef struct	s_cmd
{
	struct s_cmd	*next;
	int				cmd;
	char			*line;
	int				i;
	int				l;
	int				c;
}				t_cmd;
*/

/*
**	main.c
*/
int			main(int argc, char **argv);
void		asm_error(char *str);

/*
** asm_parse_file.c
*/
t_strct		*asm_init_strct(void);
t_str		*asm_lst_append(t_str *lst, char *str);
t_str		*asm_get_file(char *name);
int			asm_parse_file(char *name);

/*
** asm_check_file.c
*/
int			asm_check_file(t_strct *strct);

/*
** asm_check_header.c
*/
t_str			*asm_check_header(t_str *lst, t_strct *strct);

/*
** asm_check_label.c
*/
t_str			*asm_check_label(t_str *lst, t_strct *strct);

/*
** asm_util.c
*/
t_str  *asm_lst_browse(t_str *lst, int *l, int d);
int     asm_str_browse(char *str);
void    *asm_lc_error(t_strct *strct);
char        *asm_join(char *str1, char *str2);
int		asm_intlen(int i);


/*
** asm_check_command.c
*/
int asm_check_and_or(char **tab);
int asm_check_ldi(char **tab);
void  asm_check_sti(char **array, t_strct *strct, char *name, int len);
int asm_check_aff(char **tab);
int asm_check_command(int i, char *str, t_strct *strct);
/*
** asm_check_command.c
*/
int asm_check_comment(char *str);
int asm_check_live_zjmp_fork(char **tab);
int asm_check_ld(char **tab);
int asm_check_st(char **tab);
int asm_check_add_sub(char **tab);
/*
** asm_check_arg.c
*/
int asm_is_ind(char *str);
int asm_is_dir(char *str);
int asm_is_reg(char *str);

/*
** asm_header.c

header_t	*asm_init_header(void);
header_t	*asm_create_header(void);


**  asm_parse_command.c

int			asm_count_arg(char *arg);
void		asm_find_opc(char **arg, int c, int fd);
void		asm_parse_command(char *line, int fd);
void		asm_encode(char *arg, int size, int fd);


** asm_find_command.c

int			asm_find_command(char *command, int fd);


** asm_encode.c

void		asm_encode(char *arg, int size, int fd);


** asm_create_file.c

char		*asm_find_file_name(char *file);


*/

#endif
