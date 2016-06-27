/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:12:46 by mcotfas           #+#    #+#             */
/*   Updated: 2016/04/25 15:13:44 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(ssize_t n, size_t b, char base[16])
{
	ssize_t		size;
	size_t		isneg;
	size_t		i;
	char		*ret;

	size = 1;
	isneg = 0;
	i = ft_absvalue(n);
	if (n < 0)
		isneg = 1;
	while (i >= b && size++)
		i = i / b;
	i = ft_absvalue(n);
	ret = ft_strnew(size + isneg);
	while (--size >= 0 && ret)
	{
		ret[size + isneg] = base[i % b];
		i = i / b;
	}
	if (isneg && ret)
		ret[0] = '-';
	return (ret);
}
