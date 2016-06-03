/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:26:11 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/14 15:14:46 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(ssize_t n, int fd)
{
	size_t tmp;

	tmp = ft_absvalue(n);
	if (n < 0)
		ft_putchar_fd('-', (int)fd);
	if (tmp > 9)
	{
		ft_putnbr_fd(tmp / 10, fd);
		ft_putnbr_fd(tmp % 10, fd);
	}
	else
		ft_putchar_fd((char)(tmp + 48), (int)fd);
}
