/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 11:37:21 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/19 03:09:19 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_is_ind(char *str, t_byteline *new, int *c)
{
	*c = 0;
	if (!ft_isdigit(str[*c]) && str[*c] != '-')
		return (0);
	if (str[*c] == '-' && !ft_isdigit(str[*c + 1]))
		return (0);
	else if (str[*c] == '-')
		*c += 1;
	while (ft_isdigit(str[*c]))
		*c += 1;
	new->len += 2;
	return (1);
}

int		asm_is_dir(char *str, t_byteline *new, int len, int *c)
{
	*c = 0;
	if (str[0] != '%')
		return (0);
	*c += 1;
	if (str[*c] != ':')
	{
		if (!ft_isdigit(str[*c]) && str[*c] != '-')
			return (0);
		if (str[*c] == '-' && !ft_isdigit(str[*c + 1]))
			return (0);
		else if (str[*c] == '-')
			*c += 1;
		while (ft_isdigit(str[*c]))
			*c += 1;
	}
	else
	{
		*c += 1;
		while (ft_strchr(LABEL_CHARS, str[*c]) != NULL)
			*c += 1;
	}
	new->len += len;
	return (1);
}

int		asm_is_reg(char *str, t_byteline *new, int *c)
{
	int			val;

	*c = 0;
	if (str[0] != 'r')
		return (0);
	*c += 1;
	if (!ft_isdigit(str[1]))
		return (0);
	val = ft_atoi(str + 1);
	*c += asm_intlen(val);
	if (!val || val < 0 || val > REG_NUMBER)
		return (0);
	new->len += 1;
	return (1);
}

void	asm_save_arg(char *str, t_strct *strct, t_byteline *new, int c)
{
	int			d;

	d = c;
	ft_putstr(str + d);
	d += asm_str_browse(str + d);
	if (str[d] != 0)
		asm_lc_error(strct);
	str[c] = 0;
	ft_strcpy(new->name + new->name_len, str);
	strct->c += d + 1;
	new->name_len = new->name_len + c;
	new->name[new->name_len] = SEPARATOR_CHAR;
	new->name_len += 1;
}

void	asm_save_arg_finish(char **array, t_strct *strct, t_byteline *n, int c)
{
	int			d;
	char		ch;
	char		*str;
	char		*ptr;

	str = array[0] + n->label;
	ptr = array[1];
	d = c;
	d += asm_str_browse(str + d);
	ch = str[c];
	str[c] = 0;
	ft_strcpy(n->name + n->name_len, str);
	n->name[n->name_len + ft_strlen(str)] = 0;
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
