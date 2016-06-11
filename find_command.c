/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 00:22:51 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/11 00:32:03 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_find_command(char *command, int fd)
{
	if (!ft_strcmp(command, "live"))
	{
		write(fd, "0x01", 4);
		return (4);
	}
	else if (!ft_strcmp(command, "ld"))
	{
		write(fd, "0x02", 4);
		return (4);
	}
	else if (!ft_strcmp(command, "st"))
		write(fd, "0x03", 4);
	else if (!ft_strcmp(command, "add"))
		write(fd, "0x04", 4);
	else if (!ft_strcmp(command, "sub"))
		write(fd, "0x05", 4);
	else if (!ft_strcmp(command, "and"))
	{
		write(fd, "0x06", 4);
		return (4);
	}
	else if (!ft_strcmp(command, "or"))
	{
		write(fd, "0x07", 4);
		return (4);
	}
	else if (!ft_strcmp(command, "xor"))
	{
		write(fd, "0x08", 4);
		return (4);
	}
	else if (!ft_strcmp(command, "zjmp"))
		write(fd, "0x09", 4);
	else if (!ft_strcmp(command, "ldi"))
		write(fd, "0x0a", 4);
	else if (!ft_strcmp(command, "sti"))
		write(fd, "0x0b", 4);
	else if (!ft_strcmp(command, "fork"))
		write(fd, "0x0c", 4);
	else if (!ft_strcmp(command, "lld"))
	{
		write(fd, "0x0d", 4);
		return (4);
	}
	else if (!ft_strcmp(command, "lldi"))
		write(fd, "0x0e", 4);
	else if (!ft_strcmp(command, "lfork"))
		write(fd, "0x0f", 4);
	else if (!ft_strcmp(command, "aff"))
		write(fd, "0x10", 4);
	else
		asm_error("Apprend a ecrire petit scarabe");
	return (2);
}
