//
// Created by mcotfas on 19/06/16.
//

#include "corewar.h"

void write_ram(t_war *war, int value, int address)
{
	int i;
	int oct;

	i = -1;
	while(++i < 4)
	{
		oct = (value >> ( 8 * (i + 1))) & 0xff;
		war->ram[(address + i) % MEM_SIZE] = (unsigned char)oct;
	}
}
