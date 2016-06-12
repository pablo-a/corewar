/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 16:44:44 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/12 03:44:55 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** J'initialiser juste ma main structure strct
*/
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
	new->l = 0;
	new->c = 0;
	return (new);
}

/*
** J ajoute un element a t_str *file;
*/
t_str		*asm_lst_append(t_str *lst, char *str)
{
	t_str		*ptr;

	if (lst == NULL)
	{
		if ((lst = (t_str*)malloc(sizeof(t_str))) == NULL)
			return (NULL);
		ptr = lst;
	}
	else
	{
		ptr = lst;
		while (ptr->next)
			ptr = ptr->next;
		if ((ptr->next = (t_str*)malloc(sizeof(t_str))) == NULL)
			return (NULL);
		ptr = ptr->next;
	}
	ptr->next = NULL;
	if ((ptr->str = ft_strdup(str)) == NULL)
		return (NULL);
	return (lst);
}

/*
** Je read mon fichier
*/
t_str		*asm_get_file(char *name)
{
	t_str		*new;
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

/*
** J initialise ma main structure, j enregistre le fichier et je le check
*/
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
