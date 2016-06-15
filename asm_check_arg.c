/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 11:37:21 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/15 17:50:18 by vbarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int asm_is_ind(char *str)
{
	int val;
	int c;

	c = 0;
	if (!ft_isdigit(str[c]) || str[c] == '-')
		return (0);
	val = ft_atoi(str + 1);
	c += asm_intlen(val);		
	return (c);
}

int asm_is_dir(char *str)
{
	int c;
	int val;

	c = 0;
	if (str[0] != '%')
		return (0);
	c++;
	if (str[c] != ':')
	{
		if (!ft_isdigit(str[c]) || str[c] == '-')
			return (0);
		val = ft_atoi(str + 1);
		c += asm_intlen(val);		
	}
	else
	{
		c++;
		while (ft_strchr(LABEL_CHARS, str[c]) != NULL)
			c++;
	}
	return (c);
}

int asm_is_reg(char *str)
{
	int val;
	int c;

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
	return (c);
}
