/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 00:15:14 by pabril            #+#    #+#             */
/*   Updated: 2016/06/09 00:15:19 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include "libftprintf.h"

int		get_args(int argc, char **argv)
{
	int		nb_champ;

	nb_champ = 0;
	if (argc < 2 || argc > 6)
		exit(0);
	while (argc > 0)
	{
		if (ft_strcmp(argv[argc - 1], "pablo.cor") == 0)
			nb_champ++;
		argc--;
	}
	return (nb_champ);
}

int		main(int argc, char **argv)
{
	t_war	*war;
	int		nb_champ;
	int		i = 0;
	t_node	*node;

	nb_champ = get_args(argc, argv);
	war = init_war(nb_champ);
	node = war->pile_champ->first;
	while (i < nb_champ)
	{
		printf("==> %x\n", node->champ->reg_tab[0]);
		node = node->next;
		i++;
	}
}
