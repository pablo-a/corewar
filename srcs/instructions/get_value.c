/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 17:59:49 by pabril            #+#    #+#             */
/*   Updated: 2016/06/13 22:18:07 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_value(t_war *war, int pos, int size)
{
	int result;
	int i;

	i = 1;
	result = war->ram[pos % MEM_SIZE];
	while (i < size)
	{
		result = result << 8;
		result = (war->ram[(pos + i) % MEM_SIZE]) | result;
		i++;
	}
	return (result);
}