/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 12:50:44 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/12 02:43:45 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** En gros,
** cet fonctions va boucler sur strct->file;
** si la ligne est vide, remplie d'espace, commentaire: j avance
** _ Si c est un point je check name et comment sont pas deja enregistrer
** pour les enregistrer sinon erreur
** _ Sinon je compare avec LABEL_CHARS pour checker / enregistrer:
** le label / la commande
** Sinon je renvoie une errur avec la ligne / la colonne.
*/

int			asm_check_file(t_strct *strct)
{
	t_str		*ptr;
	int			l;
	int			c;
	int			d;

	l = 0;
	ptr = strct->file;
	while (ptr)
	{
		c = asm_str_browse(ptr->str);
		if (ptr->str[c] == 0 || ptr->str[c] == '#')
		{
			ptr = ptr->next;
		}
		else if (ptr->str[c] == '.')
		{
			if (strct->name != NULL && strct->comment != NULL)
				asm_lc_error(l, c);
			d = asm_check_header(ptr, strct);
			ptr = asm_lst_browse(lst, &l, d);
		}
		else if (ft_strchr(LABEL_CHARS, ptr->str[c]) != NULL)
		{
			d = asm_check_label(ptr, strct);
			ptr = asm_lst_browse(lst, &l, d);
		}
		else
			asm_lc_error(l, c);
		l++;
	}
	return (0);
}
