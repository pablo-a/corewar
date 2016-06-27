/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_ram.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 15:17:40 by pabril            #+#    #+#             */
/*   Updated: 2016/06/27 15:23:50 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void copy_ram(unsigned char ram[MEM_SIZE], unsigned char ram2[MEM_SIZE])
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ram[i] = ram2[i];
		i++;
	}
}
