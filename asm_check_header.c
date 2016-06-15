/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 00:57:40 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/15 11:47:09 by hdebard          ###   ########.fr       */
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
		i++;
	}
	return (0);
}

/*
** Je check si il y as une erreur dans le fichier apres la endquote
** sinon je recupere le nom/commentaire oklm
*/
char		*asm_save_endquote(char *str1, char *str2, t_strct *strct)
{
	int			i;
	int			j;
	char		*new;

	i = asm_check_endquote(str2);
	j = i;
	new = NULL;
	while (str2[i + 1])
	{
		if (str2[i + 1] != '#' && str2[i + 1] != ' '
			&& str2[i + 1] != 11 && str2[i + 1] != 9)
		{
			strct->c += i;
			asm_lc_error(strct);
		}
		i++;
	}
	str2[j] = 0;
	new = asm_join(str1, str2);
	str2[j] = '\"';
	return (new);
}

/*
** Comme il peut y avoir des saut de ligne dans le nom/commentaire c est un peut chiant
** a recuperer, je suis obliger de recuperer les saut de lignes pour le retourner
** a asm_check_line
*/
t_str			*asm_check_name(t_str *lst, t_strct *strct)
{
	char	*start;

	start = NULL;
	strct->c += asm_str_browse(lst->str + strct->c);
	if (lst->str[strct->c] != '\"')
		asm_lc_error(strct);
	else
		strct->c += 1;
	start = ft_strdup(lst->str + strct->c);
	if (asm_check_endquote(start) > 0)
	{
		strct->name = asm_save_endquote(NULL, start, strct);
		return (lst->next);
	}
	else
	{
		lst = lst->next;
		strct->l += 1;
		start = asm_join(start, "\n");
		while (lst)
		{
			if (asm_check_endquote(lst->str) > 0)
			{
				strct->name = asm_save_endquote(start, lst->str, strct);
				return (lst->next);
			}
			else
			{
				start = asm_join(start, lst->str);
				start = asm_join(start, "\n");
			}
			strct->l += 1;
			strct->c = 0;
			lst = lst->next;
		}
	}
	return (NULL);
}

t_str			*asm_check_coment(t_str *lst, t_strct *strct)
{
	char	*start;

	start = NULL;
	strct->c += asm_str_browse(lst->str + strct->c);
	if (lst->str[strct->c] != '\"')
		asm_lc_error(strct);
	else
		strct->c += 1;
	start = ft_strdup(lst->str + strct->c);
	if (asm_check_endquote(start) > 0)
	{
		strct->comment = asm_save_endquote(NULL, start, strct);
		return (lst->next);
	}
	else
	{
		lst = lst->next;
		strct->l += 1;
		start = asm_join(start, "\n");
		while (lst)
		{
			if (asm_check_endquote(lst->str) > 0)
			{
				strct->comment = asm_save_endquote(start, lst->str, strct);
				return (lst->next);
			}
			else
			{
				start = asm_join(start, lst->str);
				start = asm_join(start, "\n");
			}
			strct->l += 1;
			strct->c = 0;
			lst = lst->next;
		}
	}
	return (NULL);
}


/*
** je compare le content avec ".name" / ".comment" pour choisir
** quel fonction appeler, si tout ce passe bien je verifie
** la size de se que j ai enregistrer. . . . . .. . . ... . . . .. 
*/

t_str			*asm_check_header(t_str *lst, t_strct *strct)
{
	t_str *ptr;

	if (!ft_strncmp(lst->str + strct->c, NAME_CMD_STRING, 5))
	{
		strct->c += 5;
		if (!lst->str[strct->c] || lst->str[strct->c] != ' ')
			asm_lc_error(strct);
		ptr = asm_check_name(lst, strct);
		if (ft_strlen(strct->name) > PROG_NAME_LENGTH - 1)
			asm_error("Champion name too long (Max length 128)");
		return (ptr);
	}
	else if (!ft_strncmp(lst->str + strct->c, COMMENT_CMD_STRING, 8))
	{
		strct->c += 8;
		if (!lst->str[strct->c] || lst->str[strct->c] != ' ')
			asm_lc_error(strct);
		ptr = asm_check_coment(lst, strct);
		if (ft_strlen(strct->comment) > COMMENT_LENGTH - 1)
			asm_error("Champion comment too long (Max length 2048)");
		return (ptr);
	}
	return (NULL);
}
