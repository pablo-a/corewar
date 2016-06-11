/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 12:50:44 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/12 00:08:35 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
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
*/
int			asm_check_name(char *str, char **tmp, t_strct *strct)
{
	int i;
	int j;

	j = 1;
	i = asm_str_browse(str);
	if (str[i] != '\"')
		return (i);
	while (str[i + j] && str[i + j] != '\"')
		j++;
	if (str[i + j] && str[i + j] == '\"')
	{
		str[i + j] = 0;
		if (ft_strlen(str + i + 1) > PROG_NAME_LENGTH)
			asm_error("Champion name too long (Max length 128)");
		else
			strct->name = ft_strdup(str + i + 1);
		str[i + j] = '\"';
		i = asm_str_browse(str + j + 1);
		if (str[i + 1] && str[i + 1] != '#')
			return (-i);
		return (0);
	}
	else
	{
		if (ft_strlen(str + i + 1) > PROG_NAME_LENGTH)
			asm_error("Champion name too long (Max length 128)");
		else
			*tmp = ft_strdup(str + i + 1);
		return (1);
	}
}

int			asm_check_comment(char *str, char **tmp, t_strct *strct)
{
	int i;
	int j;

	j = 1;
	i = asm_str_browse(str);
	if (str[i] != '\"')
	{
		ft_putendl(str);
		return (i);
	}
	while (str[i + j] && str[i + j] != '\"')
		j++;
	if (str[i + j] && str[i + j] == '\"')
	{
		str[i + j] = 0;
//		ft_putendl(str + i + 1);
		if (ft_strlen(str + i + 1) > PROG_NAME_LENGTH)
			asm_error("Champion comment too long (Max length 2048)");
		else
			strct->comment = ft_strdup(str + i + 1);
		str[i + j] = '\"';
		i = asm_str_browse(str + j + 1);
		if (str[i + 1] && str[i + 1] != '#')
			return (-i);
		return (0);
	}
	else
	{
		if (ft_strlen(str + i + 1) > PROG_NAME_LENGTH)
			asm_error("Champion comment too long (Max length 2048)");
		else
			*tmp = ft_strdup(str + i + 1);
		return (2);
	}
}

int			add_to_tmp(char **tmp, char *buff, int token, t_strct *strct)
{
	int i;
	int j;
	char *new;

	i = 0;
	while (buff[i] && buff[i] != '\"')
		i++;
	if (buff[i])
	{
		j = asm_str_browse(buff + i + 1);
		if (buff[j])
			return (-(i+j));
		buff[i] = 0;
		new = ft_strjoin(*tmp, "\n");
		free(*tmp);
		if (token == 1)
			strct->name = ft_strjoin(new, buff);
		else if (token == 2)
			strct->comment = ft_strjoin(new, buff);
		free(new);
		return (0);
	}
	else
	{
		new = ft_strjoin(*tmp, "\n");
		free(*tmp);
		*tmp = ft_strjoin(new, buff);
		free(new);
		return (token);
	}
}

int			asm_check_header(t_list *ptr, t_strct *strct)
{
	char		*tmp;
	char		*buff;
	int			l;
	int			c;
	int			token;

	l = 0;
	c = 0;
	token = 0;
	buff = NULL;
	tmp = NULL;
	while (ptr && (strct->name == NULL || strct->comment == NULL))
	{
		buff = ptr->content;
		c = asm_str_browse(ptr->content);
		if (token == 1 || token == 2)
		{
			ft_putendl("7");
			if ((token = add_to_tmp(&tmp, buff, token, strct)) < 0)
				asm_lc_error(l, -token);
		}
		else if (!buff[c] || buff[c] == '#')
		{
			ft_putendl("4");
		}
		else if (token == 0 && buff[c] != '.')
		{
			ft_putendl("5");
			asm_lc_error(l, c);
		}
		else if (strct->name == NULL
				&& !ft_strncmp(NAME_CMD_STRING, buff + c, 5))
		{
			if ((token = asm_check_name(buff + c + 5, &tmp, strct)) < 0)
				asm_lc_error(l, -token);
		}
		else if (strct->comment == NULL
				&& !ft_strncmp(COMMENT_CMD_STRING, buff + c, 8))
		{
			if ((token = asm_check_comment(buff + c + 8, &tmp, strct)) < 0)
				asm_lc_error(l, -token);
			ft_putendl(strct->name);
			ft_putendl(strct->comment);
		}
		else
		{
			ft_putendl("1");
			asm_lc_error(l, c);
		}
		l++;
		ptr = ptr->next;
	}
	return (l);
}

int			asm_check_file(t_strct *strct)
{
	t_list		*ptr;
	int			c;

	ptr = strct->file;
	c = asm_check_header(ptr, strct);
/*	else if ((ptr = asm_check_label(ptr, strct)) < 0)
		return (1);
	else if ((ptr = asm_check_command(ptr, strct)) < 0)
	return (1); */
	// last_check;
	return (0);
}
