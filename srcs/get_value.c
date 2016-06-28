/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 17:59:49 by pabril            #+#    #+#             */
/*   Updated: 2016/06/28 14:58:11 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_value(t_war *war, int pos, int size)
{
	unsigned int	result;
	int				i;

	i = 1;
	result = war->ram[pos % MEM_SIZE];
	while (i < size)
	{
		result = result << 8;
		result = (war->ram[(pos + i) % MEM_SIZE]) | result;
		i++;
	}
	if (size == 2)
		result = (short int)result;
	if (size == 4)
		result = (int)result;
	return (result);
}
