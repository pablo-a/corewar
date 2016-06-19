/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:49:59 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/19 23:05:25 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int		asm_count_arg(char *arg)
{
	int		x;
	int		count;

	x = 0;
	count = 1;
	while (arg[x] != '\0')
	{
		if (arg[x] == SEPARATOR_CHAR)
			count++;
		x++;
	}
	return (count);
}

int		asm_find_opc(char **arg, int l, int *c)
{
	int		opc;
	int		x;
	int		a;

	a = 0;
	opc = 0;
	x = 0;
	while (x < l)
	{
		if (arg[x][0] == 'r')
			a = 1;
		else if (arg[x][0] == DIRECT_CHAR)
			a = 2;
		else
			a = 3;
		if (x == 0)
			opc = opc | (a << 6);
		else if (x == 1)
			opc = opc | (a << 4);
		else
			opc = opc | (a << 2);
		x++;
	}
	*c += 1;
	return (opc);
}

int		asm_loop(char **args, char **command, t_byteline *tmp, t_strct *strct)
{
	int				l_size;
	int				x;
	int				c;

	x = -1;
	c = tmp->label;
	tmp->label = 0;
	l_size = asm_label_size(command[0], strct);
	while (args[++x])
	{
		if (args[x][0] == 'r')
		{
			tmp->byte_line[c] = ft_atoi(args[x] + 1);
			c++;
		}
		else if (args[x][0] == '%')
		{
			if (args[x][1] == ':')
				c = asm_encode_label(tmp->byte_line,
					asm_find_label(strct, tmp, args[x] + 2), l_size, c);
			else
				c = asm_encode(tmp->byte_line, args[x] + 1, l_size, c);
		}
		else if (args[x][0] == ':')
			c = asm_encode_label(tmp->byte_line,
				asm_find_label(strct, tmp, args[x] + 1), 2, c);
		else
			c = asm_encode(tmp->byte_line, args[x], 2, c);
	}
	return (c);
}

void	asm_encode_command(t_byteline *tmp, t_strct *strct)
{
	char			**command;
	char			**args;
	int				c;
	int				len;

	c = 1;
	tmp->byte_line = (char*)malloc(tmp->len + 1);
	command = ft_strsplit(tmp->name, ' ');
	tmp->byte_line[0] = asm_find_command(command[0], strct) + 1;
	args = ft_strsplit(command[1], SEPARATOR_CHAR);
	len = asm_count_arg(command[1]);
	if (ft_strcmp(command[0], "live") && ft_strcmp(command[0], "zjmp")	\
		&& ft_strcmp(command[0], "fork") && ft_strcmp(command[0], "lfork"))
		tmp->byte_line[1] = asm_find_opc(args, len, &c);
	tmp->label = c;
	c = asm_loop(args, command, tmp, strct);
	tmp->byte_line[c] = 0;
}

int		asm_parse_command(t_strct *strct)
{
	t_byteline		*tmp;

	tmp = strct->bytelines;
	while (tmp)
	{
		if (tmp->label == 0)
			asm_encode_command(tmp, strct);
		tmp = tmp->next;
	}
	return (0);
}
