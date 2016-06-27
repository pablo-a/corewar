/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstback.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:36:57 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/16 12:57:47 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns previous link or null if fail
** alist is start of list - link is the actual link
*/

t_list			*ft_lstback(t_list *alst, t_list *link)
{
	while (alst)
	{
		if (alst->next == link)
		{
			return (alst);
		}
		alst = alst->next;
	}
	return (NULL);
}
