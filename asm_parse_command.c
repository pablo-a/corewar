/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:49:59 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/18 18:26:50 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

int		asm_find_opc(char **arg, int l)
{
	int		opc;
	int		x;
	int		a;
	int		b;
	int		c;

	a = 0;
	b = 0;
	c = 0;
	opc = 0;
	x = 0;
	while (x < l)
	{
		if (arg[x][0] == 'r')
			opc = 1;
		else if (arg[x][0] == DIRECT_CHAR)
			opc = 2;
		else if (ft_isdigit(arg[x][0]) || arg[x][0] == '-')
			opc = 3;
		if (x == 0)
			a = opc;
		else if (x == 1)
			b = opc;
		else
			c = opc;
		x++;
	}
	opc = ((a << 6) | (b << 4) | (c << 2));
	return (opc);
}

int		asm_parse_command(t_strct *strct)
{
	char			**command;
	char			**args;
	t_byteline		*tmp;
	int				l_size;
	int				x;
	int				len;
	int				c;

	tmp = strct->bytelines;
	while (tmp)
	{
		if (tmp->label == 0)
		{
			x = 0;
			c = 0;
			tmp->byte_line = (char*)malloc(tmp->len + 1);
			command = ft_strsplit(tmp->name, ' ');
			tmp->byte_line[0] = asm_find_command(command[0], strct) + 1;
			c++;
			len = asm_count_arg(command[1]);
			args = ft_strsplit(command[1], SEPARATOR_CHAR);
			l_size = asm_label_size(command[0], strct);
			if (ft_strcmp(command[0], "live") && ft_strcmp(command[0], "zjmp") \
				&& ft_strcmp(command[0], "fork") && ft_strcmp(command[0], "lfork"))
			{
				tmp->byte_line[1] = asm_find_opc(args, len);
				c++;
			}
			while (x < len)
			{
				if (args[x][0] == 'r')
				{
					tmp->byte_line[c] = ft_atoi(args[x] + 1);
					c++;
				}
				else if (args[x][0] == '%')
				{
					if (args[x][1] == ':')
						c = asm_encode_label(tmp->byte_line, asm_find_label(strct, tmp, args[x] + 2), l_size, c);
					else
						c = asm_encode(tmp->byte_line, args[x] + 1, l_size, c);
				}
				else
				{
					c = asm_encode(tmp->byte_line, args[x], 2, c);
				}
				x++;
			}
			tmp->byte_line[c] = 0;
		}
		tmp = tmp->next;
	}
	return (0);
}
