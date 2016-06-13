//
// Created by mcotfas on 13/06/16.
//
#include "corewar.h"

int update_pc(t_champ *champ, int value)
{
	int pc;

	pc = (champ->pc + value) % MEM_SIZE;
	if (pc < 0)
		pc = MEM_SIZE + pc;
	return (pc);
}