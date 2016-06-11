/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 12:50:44 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/11 00:31:11 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			asm_is_command(char *str)
{
	str = "";
	return (1);
}

int			asm_is_label(char *str)
{
	if (ft_strchr(str, LABEL_CHAR))
		return (1);
	return (0);
}

int			asm_is_header(char *str)
{
	int			x;
	char		*name;
	char		*comment;

	x = 0;
	name = NAME_CMD_STRING;
	comment = COMMENT_CMD_STRING;
	while (str[x] == name[x] || str[x] == '\0')
		x++;
	if (name[x] == '\0')
		return (1);
	while (str[x] == comment[x] || str[x] == '\0')
		x++;
	if (comment[x] == '\0')
		return (1);
	return (0);
}
