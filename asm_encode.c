/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_encode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 19:12:06 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/17 18:15:39 by vbarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_find_label(t_strct *strct, t_byteline *ptr, char *name)
{
	int diff;
	t_byteline *tmp;
	int			token;

	token = 0;
	diff = 0;
	tmp = strct->bytelines;
	while (tmp)
	{
		if (tmp == ptr)
		{
			while (tmp && ft_strcmp(tmp->name, name))
			{
				if (tmp->label == 0)
					diff += tmp->len;
				tmp = tmp->next;
			}
			if (tmp)
				token = 1;
		}
		else if (tmp->label == 1 && !ft_strcmp(tmp->name, name))
		{
			while (tmp && tmp != ptr)
			{
				if (tmp->label == 0)
					diff -= tmp->len;
				tmp = tmp->next;
			}
			token = 1;
		}
		if (tmp)
			tmp = tmp->next;
	}
	if (token == 0)
		asm_error("Wrong label name");
	return (diff);
}

int		asm_encode(char *byte_line, char *nbr, int l_size, int c_line)
{
	int n;
//	unsigned int m;
	short i;
	unsigned short j;

	n = ft_atoi(nbr);
	if (l_size == 2)
	{
		if (n >= 0)
		{
			j = (unsigned short)n;
			byte_line[c_line] = (char)((j & 0xff00) >> 8);
			byte_line[c_line + 1] = (char)((j & 0xff) >> 0);
		}
		else
		{
			i = (short)n;
			byte_line[c_line] = (char)((i & 0xff00) >> 8);
			byte_line[c_line + 1] = (char)((i & 0xff) >> 0);
		}
		c_line = c_line + 2;
	}
	else
	{
		byte_line[c_line] = (char)((n & 0xff000000) >> 24);
		byte_line[c_line + 1] = (char)((n & 0xff0000) >> 16);
		byte_line[c_line + 2] = (char)((n & 0xff00) >> 8);
		byte_line[c_line + 3] = (char)((n & 0xff) >> 0);
		c_line = c_line + 4;
	}
	return (c_line);
}

int		asm_encode_label(char *byte_line, int n, int l_size, int c_line)
{
//	unsigned int m;
	short i;
	unsigned short j;

	if (l_size == 2)
	{
		if (n >= 0)
		{
			j = (unsigned short)n;
			byte_line[c_line] = (char)((j & 0xff00) >> 8);
			byte_line[c_line + 1] = (char)((j & 0xff) >> 0);
		}
		else
		{
			i = (short)n;
			byte_line[c_line] = (char)((i & 0xff00) >> 8);
			byte_line[c_line + 1] = (char)((i & 0xff) >> 0);
		}
		c_line = c_line + 2;
	}
	else
	{
		byte_line[c_line] = (char)((n & 0xff000000) >> 24);
		byte_line[c_line + 1] = (char)((n & 0xff0000) >> 16);
		byte_line[c_line + 2] = (char)((n & 0xff00) >> 8);
		byte_line[c_line + 3] = (char)((n & 0xff) >> 0);
		c_line = c_line + 4;
	}
	return (c_line);
}
