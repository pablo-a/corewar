/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:32:06 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/16 12:13:36 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*item;

	item = (t_list*)malloc(sizeof(*item));
	if (item)
	{
		if (!content)
		{
			item->content_size = 0;
			item->content = NULL;
		}
		else
		{
			item->content = ft_memalloc(content_size);
			item->content = ft_memcpy(item->content, content, content_size);
			item->content_size = content_size;
		}
		item->next = NULL;
	}
	return (item);
}
