/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ocp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 16:40:44 by pabril            #+#    #+#             */
/*   Updated: 2016/06/23 16:41:55 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_ocp	get_ocp(int value)
{
	t_ocp	ocp;

	ocp.first = value >> 6;
	ocp.second = (value ^ (ocp.first << 6)) >> 4;
	ocp.third = (value ^ (ocp.first << 6) ^ (ocp.second << 4)) >> 2;
	ocp.fourth = value & 3;


//	ft_printf("1. value : %d, first %d, second %d, third %d\n", ocp.first, ocp.second, ocp.third);

	return (ocp);
}
