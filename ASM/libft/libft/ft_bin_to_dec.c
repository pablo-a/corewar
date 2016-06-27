/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_to_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:14:51 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 15:15:51 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_bin_to_dec(char *bin)
{
	size_t	val;

	val = 0;
	while (*bin)
	{
		if (*bin == '1')
			val = (val << 1) | 1;
		else if (*bin == '0')
			val <<= 1;
		else
			break ;
		bin++;
	}
	return (val);
}
