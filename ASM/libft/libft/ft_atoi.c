/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:38:39 by mcotfas           #+#    #+#             */
/*   Updated: 2015/12/06 01:11:29 by mcotfas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t				ft_atoi(char const *str)
{
	int		sign;
	ssize_t	ret;

	sign = 1;
	ret = 0;
	while (ft_isspace(*str))
		str++;
	if (str[0] == '-')
	{
		sign = -1;
		str++;
	}
	else if (str[0] == '+')
		str++;
	else if (!ft_isdigit(*str))
		return (0);
	while (ft_isdigit(*str))
		ret = ret * 10 + (*str++ - '0');
	return (ret * sign);
}
