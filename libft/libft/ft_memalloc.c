/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:02:46 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/12 14:27:00 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void				*ft_memalloc(size_t size)
{
	void	*m;

	m = malloc(size);
	if (m != NULL)
		ft_memset(m, 0, size);
	return (m);
}
