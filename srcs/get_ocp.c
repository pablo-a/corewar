//
// Created by mcotfas on 15/06/16.
//

#include "corewar.h"

t_ocp get_ocp(int value)
{
	//TODO Clean code :

	t_ocp  ocp;
//
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//
//	value = ((1 << 6) | (1 << 4) | (1 << 2));

	ocp.first = value >> 6;
	ocp.second = (value ^ (ocp.first << 6)) >> 4;
	ocp.third = (value ^ (ocp.first << 6) ^ (ocp.second << 4)) >> 2;
	ocp.fourth = value & 3;

	ft_printf("value : %d // 1 : %d // 2 : %d // 3 : %d // 4 : %d\n", value, ocp.first, ocp.second, ocp.third, ocp.fourth);



	return (ocp);
}
