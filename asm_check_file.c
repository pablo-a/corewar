/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 12:50:44 by vbarrete          #+#    #+#             */
/*   Updated: 2016/06/12 04:32:27 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** En gros,
** cet fonctions va boucler sur strct->file;
** si la ligne est vide, remplie d'espace, commentaire: j avance
** _ Si c est un point je check name et commente sont pas deja enregistrer
** pour les enregistrer sinon erreur
** _ Sinon je compare avec LABEL_CHARS pour checker / enregistrer:
** le label / la commande
** Sinon je renvoie une erreur avec la ligne / la colonne.
*/

int			asm_check_file(t_strct *strct)
{
	t_str		*ptr;

	ptr = strct->file;
	while (ptr)
	{
		printf("[Tour: %d]\n", strct->l + 1);
		strct->c = asm_str_browse(ptr->str);
		if (ptr->str[strct->c] == 0 || ptr->str[strct->c] == '#')
		{
			ptr = ptr->next;
		}
		else if (ptr->str[strct->c] == '.')
		{
			if (strct->name != NULL && strct->comment != NULL)
				asm_lc_error(strct);
			if ((ptr = asm_check_header(ptr, strct)) == NULL)
				exit(0);
		}
		else if (ft_strchr(LABEL_CHARS, ptr->str[strct->c]) != NULL)
		{
			ft_putendl(strct->name);
			ft_putendl(strct->comment);
			if ((ptr = asm_check_label(ptr, strct)) == NULL)
				exit(0);
		}
		else
			asm_lc_error(strct);
		strct->c = 0;
		strct->l += 1;
	}
	return (0);
}
