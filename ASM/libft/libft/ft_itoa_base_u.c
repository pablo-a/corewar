/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:14:06 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 15:14:22 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base_u(size_t n, size_t b, char base[16])
{
	ssize_t		size;
	size_t		i;
	char		*ret;

	size = 1;
	i = n;
	while (i >= b && size++)
		i = i / b;
	i = n;
	ret = ft_strnew(size);
	while (--size >= 0 && ret)
	{
		ret[size] = base[i % b];
		i = i / b;
	}
	return (ret);
}
