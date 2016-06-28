/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ram.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 16:58:53 by pabril            #+#    #+#             */
/*   Updated: 2016/06/27 15:39:28 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** ALLOW TO WRITE INTO THE RAM
** NEED A VALUE AND AN ADDRESS
*/

void	write_ram(t_war *war, t_champ *champ, int value, int address)
{
	int i;
	int j;
	int oct;

	i = -1;
	j = 3;
	while (++i < 4)
	{
		oct = (value >> (8 * (j--))) & 0xff;
		war->ram[(address + i) % MEM_SIZE] = (unsigned char)oct;
		war->ram_info[(address + i) % MEM_SIZE] = -champ->id;
	}
	refresh_ram(war, address, 4, -champ->id);
}
