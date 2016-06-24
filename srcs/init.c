/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:35:50 by pabril            #+#    #+#             */
/*   Updated: 2016/06/24 06:41:34 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Les deux fonctions load servent a charger notre tableau d'instruction
** dans notre structure principale.
*/

static int	load_1(t_op *op_tab)
{
	op_tab[0] = (t_op){"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, live};
	op_tab[1] = (t_op){"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, ld};
	op_tab[2] = (t_op){"st", 2, {T_REG, T_IND | T_REG}, 3, 5,
														"store", 1, 0, st};
	op_tab[3] = (t_op){"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1,
		0, add};
	op_tab[4] = (t_op){"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction",
	1, 0, sub};
	op_tab[5] = (t_op){"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND |
	T_DIR, T_REG}, 6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, and};
	op_tab[6] = (t_op){"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR,
		T_REG}, 7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, or};
	op_tab[7] = (t_op){"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR,
		T_REG}, 8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, xor};
	op_tab[8] = (t_op){"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, zjmp};
	op_tab[9] = (t_op){"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		10, 25, "load index", 1, 1, ldi};
	return (0);
}

static int	load_2(t_op *op_tab)
{
	op_tab[10] = (t_op){"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		11, 25, "store index", 1, 1, sti};
	op_tab[11] = (t_op){"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, cor_fork};
	op_tab[12] = (t_op){"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load",
		1, 0, lld};
	op_tab[13] = (t_op){"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}
		, 14, 50, "long load index", 1, 1, lldi};
	op_tab[14] = (t_op){"lfork", 1, {T_DIR}, 15, 1000,
													"long fork", 0, 1, lfork};
	op_tab[15] = (t_op){"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, aff};
	op_tab[16] = (t_op){"\0", 0, {0}, 0, 0, "\0", 0, 0, NULL};
	return (0);
}

t_champ		*init_champ(ssize_t id)
{
	t_champ	*champ;
	int		i;

	i = -1;
	champ = (t_champ *)malloc(sizeof(t_champ));
	champ->id = (int)-id;
	champ->pc = 0;
	champ->carry = 0;
	champ->cpt_interne = 1;
	champ->cpt_live[0] = 0;
	champ->cpt_live[1] = 0;
	champ->header = NULL;
	champ->instructions = NULL;
	champ->is_dead = 0;
	champ->id_process = 1;
	while (i++ < REG_NUMBER)
		champ->reg_tab[i] = 0;
	champ->reg_tab[0] = (int)-id;
	champ->player = (t_player *)malloc(sizeof(t_player));
	champ->player->id = -id;
	champ->player->last_live = 0;
	champ->player->nbr_live = 0;
	champ->player->is_dead = 0;
	champ->player->current_nbr_live = 0;
	return (champ);
}

t_op		*init_op_tab(void)
{
	t_op	*op_tab;

	op_tab = (t_op *)malloc(sizeof(t_op) * 17);
	load_1(op_tab);
	load_2(op_tab);
	return (op_tab);
}

t_war		*init_war(t_args *args)
{
	t_war	*war;
	int		i;

	i = 0;
	war = (t_war *)malloc(sizeof(t_war));
	while (i < MEM_SIZE)
	{
		war->ram_info[i] = 0;
		war->ram[i] = 0;
		i++;
	}
	war->cycle_to_die = CYCLE_TO_DIE;
	war->current_cycle = 0;
	war->current_live_nb = 1;
	war->max_check = -1;
	war->op_tab = init_op_tab();
	war->args = args;
	war->pile_champ = new_pile();
	war->ncurse = NULL;
	return (war);
}
