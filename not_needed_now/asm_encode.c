/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 00:25:26 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/11 00:32:48 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	asm_encode(char *arg, int size, int fd)
{
	char	*hexa;
	char	*h0;
	int		x;

	hexa = ft_itoa_base(ft_atoi(arg), 16, BASE_MIN);
	h0 = ft_strnew(size - ft_strlen(hexa));
	x = 0;
	while (x < (int)(size - ft_strlen(hexa)))
	{
		h0[x] = '0';
		x++;
	}
	hexa = ft_strjoin(h0, hexa);
	x = 0;
	while (x < size)
	{
		if (x % 2 == 0)
			write(fd, ",0x", 3);
		write(fd, &hexa[x], 1);
		x++;
	}
}
