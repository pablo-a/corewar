/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:47:58 by pabril            #+#    #+#             */
/*   Updated: 2016/06/24 06:42:54 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	copy_father(t_champ *father, t_champ *son)
{
	int i;

	i = -1;
	while (i++ < 16)
		son->reg_tab[i] = father->reg_tab[i];
	son->id = father->id;
	son->carry = father->carry;
	son->cpt_interne = 1;
	son->is_dead = 0;
	son->cpt_live[0] = father->cpt_live[0];
	son->cpt_live[1] = 0;
	son->header = father->header;
	son->instructions = NULL;
	son->player = father->player;
	return (0);
}

int			cor_fork(t_war *war, t_champ *champ)
{
	t_champ	*son;

	if ((son = (t_champ *)malloc(sizeof(t_champ))) == NULL)
		perror_exit("Malloc error ");
	copy_father(champ, son);
	son->pc = calc_pc(champ->pc, get_value(war, champ->pc + 1, 2) % IDX_MOD);
	son->id_process = war->pile_champ->nb_elem + 1;
	pile_append(war->pile_champ, son);
	refresh_pc(war, champ, champ->pc, champ->pc + 3);
	refresh_pc(war, champ, son->pc, son->pc);
	champ->pc = calc_pc(champ->pc, 3);
	return (0);
}
