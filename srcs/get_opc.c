//
// Created by mcotfas on 15/06/16.
//

#include "corewar.h"

t_opc get_opc(int value)
{
	//TODO Clean code :

	t_opc  opc;
//
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//
//	value = ((1 << 6) | (1 << 4) | (1 << 2));

	opc.first = value >> 6;
	opc.second = (value ^ (opc.first << 6)) >> 4;
	opc.third = (value ^ (opc.first << 6) ^ (opc.second << 4)) >> 2;

	ft_printf("a : %d // b : %d // c : %d // d : %d\n", value, opc.first, opc.second, opc.third);



	return (opc);
}
