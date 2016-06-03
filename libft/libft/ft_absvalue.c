/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 21:37:08 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/14 15:21:34 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_absvalue(ssize_t n)
{
	size_t i;

	if (n < 0)
		i = (size_t)-n;
	else
		i = (size_t)n;
	return (i);
}
