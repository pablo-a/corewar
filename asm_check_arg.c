/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 11:37:21 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/18 17:44:41 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			asm_is_ind(char *str, t_byteline *new)
{
	int		c;

	c = 0;
	if (!ft_isdigit(str[c]) && str[c] != '-')
		return (0);
	if (str[c] == '-' && !ft_isdigit(str[c + 1]))
		return (0);
	else if (str[c] == '-')
		c++;
	while (ft_isdigit(str[c]))
		c++;
	new->len += 2;
	return (c);
}

int			asm_is_dir(char *str, t_byteline *new, int len)
{
	int			c;

	c = 0;
	if (str[0] != '%')
		return (0);
	c++;
	if (str[c] != ':')
	{
		if (!ft_isdigit(str[c]) && str[c] != '-')
			return (0);
		if (str[c] == '-' && !ft_isdigit(str[c + 1]))
			return (0);
		else if (str[c] == '-')
			c++;
		while (ft_isdigit(str[c]))
			c++;
	}
	else
	{
		c++;
		while (ft_strchr(LABEL_CHARS, str[c]) != NULL)
			c++;
	}
	new->len += len;
	return (c);
}

int			asm_is_reg(char *str, t_byteline *new)
{
	int			val;
	int			c;

	c = 0;
	if (str[0] != 'r')
		return (0);
	c++;
	if (!ft_isdigit(str[1]))
		return (0);
	val = ft_atoi(str + 1);
	c += asm_intlen(val);
	if (!val || val < 0 || val > REG_NUMBER)
		return (0);
	new->len += 1;
	return (c);
}

void		asm_save_arg(char *str, t_strct *strct, char *name, int *len, int c)
{
	int			d;

	d = c;
	ft_putstr(str + d);
	d += asm_str_browse(str + d);
	if (str[d] != 0)
		asm_lc_error(strct);
	str[c] = 0;
	ft_strcpy(name + *len, str);
	strct->c += d + 1;
	*len = *len + c;
	name[*len] = SEPARATOR_CHAR;
	*len += 1;
}

void		asm_save_arg_finish(char *str, char *ptr, t_strct *strct, char *name, int *len, int c)
{
	int			d;
	char		ch;

	d = c;
	d += asm_str_browse(str + d);
	ch = str[c];
	str[c] = 0;
	ft_strcpy(name + *len, str);
	str[c] = ch;
	strct->c += d;
	if (str[d] != COMMENT_CHAR)
	{
		if (str[d] != 0)
			asm_lc_error(strct);
		else if (ptr)
			asm_lc_error(strct);
	}
}
