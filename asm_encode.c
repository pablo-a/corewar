/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_encode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 19:12:06 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/18 20:39:34 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_label_loop(t_byteline *tmp, t_byteline *ptr, char *name, int *diff)
{
	int token;

	token = 0;
	if (tmp == ptr)
	{
		while (tmp && ft_strcmp(tmp->name, name))
		{
			if (tmp->label == 0)
				*diff += tmp->len;
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
				*diff -= tmp->len;
			tmp = tmp->next;
		}
		token = 1;
	}
	return (token);
}

int		asm_find_label(t_strct *strct, t_byteline *ptr, char *name)
{
	int			diff;
	t_byteline	*tmp;
	int			token;

	token = 0;
	diff = 0;
	tmp = strct->bytelines;
	while (tmp)
	{
		if (tmp == ptr || (tmp->label == 1 && !ft_strcmp(tmp->name, name)))
		{
			token = asm_label_loop(tmp, ptr, name, &diff);
			break ;
		}
		tmp = tmp->next;
	}
	if (token == 0)
		asm_error("Wrong label name");
	return (diff);
}

int		asm_encode(char *byte_line, char *nbr, int l_size, int c)
{
	int				n;
	short			i;

	n = ft_atoi(nbr);
	if (l_size == 2)
	{
		i = (short)n;
		byte_line[c] = (char)((i & 0xff00) >> 8);
		byte_line[c + 1] = (char)((i & 0xff) >> 0);
		c = c + 2;
	}
	else
	{
		byte_line[c] = (char)((n & 0xff000000) >> 24);
		byte_line[c + 1] = (char)((n & 0xff0000) >> 16);
		byte_line[c + 2] = (char)((n & 0xff00) >> 8);
		byte_line[c + 3] = (char)((n & 0xff) >> 0);
		c = c + 4;
	}
	return (c);
}

int		asm_encode_label(char *byte_line, int n, int l_size, int c)
{
	short			i;

	if (l_size == 2)
	{
		i = (short)n;
		byte_line[c] = (char)((i & 0xff00) >> 8);
		byte_line[c + 1] = (char)((i & 0xff) >> 0);
		c = c + 2;
	}
	else
	{
		byte_line[c] = (char)((n & 0xff000000) >> 24);
		byte_line[c + 1] = (char)((n & 0xff0000) >> 16);
		byte_line[c + 2] = (char)((n & 0xff00) >> 8);
		byte_line[c + 3] = (char)((n & 0xff) >> 0);
		c = c + 4;
	}
	return (c);
}
