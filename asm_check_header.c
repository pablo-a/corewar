/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 00:57:40 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/12 02:57:38 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Je cherche la endquote et retourne la pos si je trouve
*/
int			asm_check_endquote(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			return (i);
		str[i];
	}
	return (0);
}

/*
** Je check si il y as une erreur dans le fichier apres la endquote
** sinon je recupere le nom/commentaire oklm
*/
char		*asm_save_endquote(int c, char *str1, char *str2)
{
	int			i;
	char		*new;

	i = 0;
	new = NULL;
	while (str2[c + i + 1])
	{
		if (str2[c + i + 1] != '#' || str2[c + i + 1] != ' ')
			asm_lc_error(l, c + i + 1);
		i ++;
	}
	str2[i] = 0;
	new = asm_join(str1, str2);
	str2[i] = '\"';
	return (asm_join(str1, str2));
}

/*
** Comme il peut y avoir des saut de ligne dans le nom/commentaire c est un peut chiant
** a recuperer, je suis obliger de recuperer les saut de lignes pour le retourner
** a asm_check_line
*/
int			asm_check_name(t_str *lst, t_strct *strct);
{
	char	*start;
	int		d;
	int		c;

	d = 1;
	start = NULL;
	if (ft_strncmp(" \"", lst->str + 8, 2))
		return (NULL);
	start = ft_strdup(lst->str + 10);
	if ((c = asm_check_endquote(start)) != 0)
	{
		str->comment = asm_save_endquote(c, "", start);
		return (1);
	}
	else
	{
		lst = lst->next;
		d++;
		while (lst)
		{
			if ((c = asm_check_endquote(lst->str)) != 0)
			{
				strct->comment = asm_save_endquote(c, start, lst->str);
				return (d);
			}
			else
				start = asm_join(start, lst->str);
			d++;
			lst = lst->next;
		}
	}
	return (-1);
}

int			asm_check_name(t_str *lst, t_strct *strct)
{
	char	*start;
	int		d;
	int		c;

	d = 1;
	start = NULL;
	if (ft_strncmp(" \"", lst->str + 8, 2))
		return (NULL);
	start = ft_strdup(lst->str + 10);
	if ((c = asm_check_endquote(start)) != 0)
	{
		str->comment = asm_save_endquote(c, "", start);
		return (1);
	}
	else
	{
		lst = lst->next;
		d++;
		while (lst)
		{
			if ((c = asm_check_endquote(lst->str)) != 0)
			{
				strct->comment = asm_save_endquote(c, start, lst->str);
				return (d);
			}
			else
				start = asm_join(start, lst->str);
			d++;
			lst = lst->next;
		}
	}
	return (-1);
}


/*
** je compare le content avec ".name" / ".comment" pour choisir
** quel fonction appeler, si tout ce passe bien je verifie
** la size de se que j ai enregistrer. . . . . .. . . ... . . . .. 
*/

int			asm_check_header(t_str *lst, t_strct *strct)
{
	int		l;

	if (!ft_strncmp(lst->name, NAME_CMD_STRING, 5))
	{
		l = asm_check_name(lst, strct);
		if (ft_strlen(strct->name) > PROG_NAME_LENGTH - 1)
			asm_error("Champion name too long (Max length 128)");
		return (l);
	}
	else if (!ft_strncmp(lst->name, COMMENT_CMD_STRING, 8))
	{
		l = asm_check_comment(lst, strct);
		if (ft_strlen(strct->comment) > COMMENT_LENGTH - 1)
			asm_error("Champion comment too long (Max length 2048)");
		return (l);
	}
	return (-1);
}
