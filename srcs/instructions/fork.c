/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:47:58 by pabril            #+#    #+#             */
/*   Updated: 2016/06/13 18:17:18 by pabril           ###   ########.fr       */
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
	son->cpt_live[0] = 0;
	son->cpt_live[1] = 0;
	son->header = NULL;
	son->instructions = NULL;
	return (0);
}

int			cor_fork(t_war *war, t_champ *champ)
{
	t_champ	*son;

	if ((son = (t_champ *)malloc(sizeof(t_champ))) == NULL)
		perror_exit("Malloc error ");
	copy_father(champ, son);
	son->pc = get_value(war, champ->pc + 1, 2) % IDX_MOD;
	if (son->pc < 0)
		son->pc = MEM_SIZE + son->pc;
	pile_append(war->pile_champ, son);
	champ->carry = 1;
	return (0);
}
