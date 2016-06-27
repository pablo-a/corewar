/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:57:36 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/16 10:09:27 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *item;
	t_list *tmp;

	item = *alst;
	while (item)
	{
		tmp = item->next;
		ft_lstdelone(&item, del);
		item = tmp;
	}
	*alst = NULL;
}
