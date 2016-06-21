/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:47:58 by pabril            #+#    #+#             */
/*   Updated: 2016/06/14 01:42:59 by pabril           ###   ########.fr       */
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

	//TODO check that :
	son->is_dead = 0;
	son->cpt_live[0] = 0;
	son->cpt_live[1] = 0;
//	son->cpt_live[0] = father->cpt_live[0];
//	son->cpt_live[1] = father->cpt_live[1];

	son->header = father->header;
	son->instructions = NULL;
	if (father->father != NULL)
		son->father = father->father;
	else
		son->father = father;

	return (0);
}

int			cor_fork(t_war *war, t_champ *champ)
{
	t_champ	*son;

	//TODO ok ?

	if ((son = (t_champ *)malloc(sizeof(t_champ))) == NULL)
		perror_exit("Malloc error ");
	copy_father(champ, son);
	son->pc = calc_pc(champ->pc ,get_value(war, champ->pc + 1, 2) % IDX_MOD);
	pile_append(war->pile_champ, son);
	champ->pc = calc_pc(champ->pc, 3);
	champ->born = war->current_cycle;
	return (0);
}
