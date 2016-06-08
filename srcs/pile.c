/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:18:40 by pabril            #+#    #+#             */
/*   Updated: 2016/06/09 00:08:25 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libftprintf.h"

t_pile	*new_pile(void)
{
	t_pile	*pile;

	pile = (t_pile *)malloc(sizeof(*pile));
	if (pile == NULL)
		return (0);
	pile->nb_elem = 0;
	pile->first = NULL;
	pile->last = NULL;
	return (pile);
}

int		pile_append(t_pile *pile, t_champ *champ)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(*node));
	node->champ = champ;
	node->next = NULL;
	if (pile->first != NULL)
	{
		node->prev = pile->last;
		pile->last->next = node;
		pile->last = node;
	}
	else
	{
		node->prev = NULL;
		pile->first = node;
		pile->last = node;
	}
	pile->nb_elem++;
	return (1);
}

int		pile_prepend(t_pile *pile, t_champ *champ)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(*node));
	node->champ = champ;
	node->prev = NULL;
	if (pile->first != NULL)
	{
		pile->first->prev = node;
		node->next = pile->first;
		pile->first = node;
	}
	else
	{
		node->next = NULL;
		pile->first = node;
		pile->last = node;
	}
	pile->nb_elem++;
	return (1);
}

int		free_pile(t_pile **pile)
{
	t_node *temp;
	t_node *del;

	if (*pile != NULL)
	{
		temp = (*pile)->last;
		while (temp != NULL)
		{
			del = temp;
			temp = temp->prev;
			free(del);
		}
	}
	free(*pile);
	*pile = NULL;
	return (1);
}
