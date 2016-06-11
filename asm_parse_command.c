/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 14:31:56 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/11 00:30:50 by hdebard          ###   ########.fr       */
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

void	asm_find_opc(char **arg, int c, int fd)
{
	int		x;
	int		y;
	char	*bin;
	char	*hexa;

	bin = ft_strnew(8);
	x = 0;
	y = 0;
	while (x < c)
	{
		if (arg[x][0] == 'r')
		{
			bin[y] = '0';
			bin[y + 1] = '1';
		}
		else if (arg[x][0] == DIRECT_CHAR)
		{
			bin[y] = '1';
			bin[y + 1] = '0';
		}
		else if (ft_isdigit(arg[x][0]))
		{
			bin[y] = '1';
			bin[y + 1] = '1';
		}
		y += 2;
		x++;
	}
	while (y < 8)
	{
		bin[y] = '0';
		y++;
	}
	hexa = ft_itoa_base(ft_bin_to_dec(bin), 16, BASE_MIN);
	write(fd, ",0x", 3);
	write(fd, hexa, 2);
}

void	asm_parse_command(char *line, int fd)
{
	char	**split;
	char	**arg;
	char	*command;
	char	*hexa;
	int		x;
	int		label_size;

	split = ft_strsplit(line, ' ');
	command = split[0];
	arg = ft_strsplit(split[1], SEPARATOR_CHAR);
	label_size = asm_find_command(command, fd);
	if (ft_strcmp(command, "live") && ft_strcmp(command, "zjmp") \
		&& ft_strcmp(command, "fork") && ft_strcmp(command, "lfork"))
		asm_find_opc(arg, asm_count_arg(split[1]), fd);
	x = 0;
	while (x < asm_count_arg(split[1]))
	{
		if (arg[x][0] == 'r')
		{
			write(fd, ",0x", 3);
			hexa = ft_itoa_base(ft_atoi(arg[x] + 1), 16, BASE_MIN);
			if (ft_strlen(hexa) == 1)
				write(fd, "0", 1);
			write(fd, hexa, 2);
		}
		else if (arg[x][0] == '%')
		{
			if (arg[x][1] == ':')
			{
//				find_label()
				;
			}
			else
				asm_encode(arg[x] + 1, label_size * 2, fd);
		}
		else
			asm_encode(arg[x], 4, fd);
		x++;
	}
}
