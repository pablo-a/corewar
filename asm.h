/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 15:31:03 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/12 02:32:21 by hdebard          ###   ########.fr       */
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
	char				*name;
	char				*comment;


	header_t	*header;
	char		*program;
}				t_strct;

typedef struct	s_str
{
	struct s_str	*next;
	char			*str;
}				t_str;
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
** asm_parse_header.c
*/
int			asm_check_header(t_str *lst, t_strct *strct);


/*
** asm_util.c
*/
t_str  *asm_lst_browse(t_str *lst, int *l, int d);
int     asm_str_browse(char *str);
void    *asm_lc_error(int l, int c);
char        *asm_join(char *str1, char *str2);


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
