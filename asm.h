/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 15:31:03 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/12 01:00:08 by hdebard          ###   ########.fr       */
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
	t_list		*file;
	char		*name;
	char		*comment;



	header_t	*header;
	char		*program;
}				t_strct;

/*
**	main.c
*/
int			main(int argc, char **argv);
void		asm_error(char *str);

/*
** asm_parse_file.c
*/
t_strct		*asm_init_strct(void);
t_list		*asm_lst_append(t_list *list, void *data);
t_list		*asm_get_file(char *name);
int			asm_parse_file(char *name);

/*
** asm_check_file.c
*/
int			asm_check_file(t_strct *strct);

/*
** asm_parse_header.c
*/
int			asm_check_header(t_strct *strct);


/*
** asm_util.c
*/
t_list  *asm_lst_browse(t_list *lst, int c);
int     asm_str_browse(char *str);
void    *asm_lc_error(int l, int c);



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
