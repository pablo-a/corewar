/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 16:44:44 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/12 00:56:44 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_strct		*asm_init_strct(void)
{
	t_strct		*new;

	if ((new = (t_strct*)malloc(sizeof(t_strct))) == NULL)
		return (NULL);
	new->file = NULL;
	new->name = NULL;
	new->comment = NULL;
	new->header = NULL;
	new->program = NULL;
	return (new);
}

t_list		*asm_lst_append(t_list *list, void *data)
{
	t_list		*ptr;

	if (list == NULL)
	{
		if ((list = (t_list*)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		ptr = list;
	}
	else
	{
		ptr = list;
		while (ptr->next)
			ptr = ptr->next;
		if ((ptr->next = (t_list*)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		ptr = ptr->next;
	}
	ptr->next = NULL;
	if ((ptr->content = ft_strdup(data)) == NULL)
		return (NULL);
	return (list);
}

t_list		*asm_get_file(char *name)
{
	t_list		*new;
	char		*buff;
	int			fd;

	new = NULL;
	buff = NULL;
	if ((fd = open(name, O_RDONLY)) == -1)
		asm_error("Fichier Inexistant");
	while (get_next_line(fd, &buff) == 1)
	{
		if (!buff)
			break ;
		new = asm_lst_append(new, buff);
		free(buff);
		buff = NULL;
	}
	if (buff != NULL)
	{
		new = asm_lst_append(new, buff);
		free(buff);
	}
	close(fd);
	return (new);
}

int			asm_parse_file(char *name)
{
	t_strct		*strct;

	if (!(strct = asm_init_strct()))
		return (1);
	else if (!(strct->file = asm_get_file(name)))
		return (1);
	else if (asm_check_file(strct) != 0)
		return (1);
	return (0);
}
