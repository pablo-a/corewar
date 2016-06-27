/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 21:58:45 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/20 00:45:50 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int		asm_intlen(int i)
{
	int		len;

	len = 0;
	if (i < 0 || i == 0)
		len++;
	while (i != 0)
	{
		len++;
		i /= 10;
	}
	return (len);
}

int		asm_str_browse(char *str)
{
	int		i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'))
		i++;
	return (i);
}

void	*asm_lc_error(t_strct *strct)
{
	ft_putstr("ERROR: [");
	ft_putnbr(strct->l + 1);
	ft_putstr(", ");
	ft_putnbr(strct->c + 1);
	ft_putendl("]");
	exit(0);
}

char	*asm_join(char *str1, char *str2)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (str1 == NULL)
		return (ft_strdup(str2));
	else if (str2 == NULL)
		return (str1);
	else
	{
		new = (char*)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
		while (str1[++i])
			new[i] = str1[i];
		while (str2[++j])
			new[i + j] = str2[j];
		new[i + j] = 0;
		free(str1);
		return (new);
	}
}

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
