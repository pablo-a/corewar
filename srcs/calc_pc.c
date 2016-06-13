//
// Created by mcotfas on 13/06/16.
//
#include "corewar.h"

int 	calc_pc(int pc, int value)
{
	pc = (pc + value) % MEM_SIZE;
	if (pc < 0)
		pc = MEM_SIZE + pc;
	return (pc);
}