/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 15:31:03 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/11 00:33:06 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include <stdlib.h>
# include "libft/includes/libft.h"
# include "op.h"

/*
** check.c
*/
int			asm_is_command(char *str);
int			asm_is_label(char *str);
int			asm_is_header(char *str);

/*
**  parse.c
*/
int			asm_count_arg(char *arg);
int			asm_find_command(char *command, int fd);
void		asm_find_opc(char **arg, int c, int fd);
void		asm_parse_command(char *line, int fd);
void		asm_encode(char *arg, int size, int fd);

/*
** main.c
*/
void		asm_error(char *str);
void		asm_parse(int fd, char *name);
char		*asm_find_file_name(char *file);

#endif
