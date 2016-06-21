/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:48:36 by pabril            #+#    #+#             */
/*   Updated: 2016/06/14 02:00:51 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libftprintf.h"

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
	if (father->father != NULL)
		son->father = father->father;
	else
		son->father = father;
	son->instructions = NULL;
	return (0);
}

int			lfork(t_war *war, t_champ *champ)
{
	t_champ	*son;

	if ((son = (t_champ *)malloc(sizeof(t_champ))) == NULL)
		perror_exit("Malloc error ");
	copy_father(champ, son);
	son->pc = calc_pc(champ->pc ,get_value(war, champ->pc + 1, 2));

//	ft_printf("FORK at cycle %d AND clone pc is at pc %d\n",war->current_cycle, son->pc);

	pile_append(war->pile_champ, son);
	//update pc after fork :
	champ->pc = calc_pc(champ->pc, 3);
	champ->born = war->current_cycle;

	//TODO Handle carry :
	champ->carry = 1;
	return (0);
}
