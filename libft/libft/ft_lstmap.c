/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 18:50:45 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/16 14:04:50 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*pos;

	if (!lst)
		return (NULL);
	pos = ft_lstnew(lst->content, lst->content_size);
	pos = f(lst);
	new = pos;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew(lst->content, lst->content_size);
		if (!tmp)
			return (NULL);
		tmp = (*f)(lst);
		pos->next = tmp;
		pos = tmp;
		lst = lst->next;
	}
	return (new);
}
