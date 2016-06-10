/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:35:50 by pabril            #+#    #+#             */
/*   Updated: 2016/06/10 12:01:13 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/* Les deux fonctions load servent a charger notre tableau d'instruction 
** dans notre structure principale.
*/
static int	load_1(t_op *op_tab)
{
	op_tab[0] = (t_op){"live", 1, {T_DIR}, 1, 10, "alive", 0, 0};
	op_tab[1] = (t_op){"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0};
	op_tab[2] = (t_op){"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0};
	op_tab[3] = (t_op){"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1,
		0};
	op_tab[4] = (t_op){"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction",
	1, 0}; op_tab[5] = (t_op){"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND |
	T_DIR, T_REG}, 6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0};
	op_tab[6] = (t_op){"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR,
		T_REG}, 7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0};
	op_tab[7] = (t_op){"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR,
		T_REG}, 8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0};
	op_tab[8] = (t_op){"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1};
	op_tab[9] = (t_op){"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		10, 25, "load index", 1, 1};
	return (0);
}

static int	load_2(t_op *op_tab)
{
	op_tab[10] = (t_op){"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		11, 25,
	"store index", 1, 1};
	op_tab[11] = (t_op){"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1};
	op_tab[12] = (t_op){"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load",
		1, 0};
	op_tab[13] = (t_op){"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}
		, 14, 50, "long load index", 1, 1};
	op_tab[14] = (t_op){"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1};
	op_tab[15] = (t_op){"aff", 1, {T_REG}, 16, 2, "aff", 1, 0};
	op_tab[16] = (t_op){"\0", 0, {0}, 0, 0, "\0", 0, 0};
	return (0);
}

t_champ		*init_champ(ssize_t id)
{
	t_champ	*champ;
	int		i;

	i = -1;
	champ = (t_champ *)malloc(sizeof(t_champ));
	champ->id = (int)id;
	champ->pc = 0;
	champ->carry = 0;
	champ->cpt_interne = 0;
	while (i++ < REG_NUMBER)
		champ->reg_tab[i] = 0;
	champ->reg_tab[0] = -(int)id;
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
		war->ram[i] = 0;
		i++;
	}
	war->cycle_to_die = CYCLE_TO_DIE;
	war->current_cycle = 0;
	war->op_tab = init_op_tab();
	war->args = args;
	war->pile_champ = new_pile();
	return (war);
}
