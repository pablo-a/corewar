/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 16:44:44 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/11 00:29:44 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		asm_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

void		asm_parse(int fd, char *name)
{
	char		*line;
	int			fd2;

	fd2 = open(name, O_CREAT | O_RDWR | O_TRUNC, S_IWRITE | S_IREAD);
	while (get_next_line(fd, &line) == 1)
	{
/*
** if (is_header(line))
**	parse_header(line, fd2);
**	;
** else if (is_label(line))
**	parse_label(line, fd2);
**	;
** else if (is_command(line))
*/
		asm_parse_command(line, fd2);
		write(fd2, "\n", 1);
	}
	close(fd2);
}

char		*asm_find_file_name(char *file)
{
	char		**split;
	char		*new;

	split = ft_strsplit(file, '.');
	new = split[0];
	new = ft_strjoin(new, ".cor");
	return (new);
}
