/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 00:15:14 by pabril            #+#    #+#             */
/*   Updated: 2016/06/10 12:26:50 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include "libftprintf.h"

int		get_args(int argc, char **argv, t_war *war)
{
	int		i;
	t_champ	*champ;

	i = 1;
	if (argc < 2 || argc > 10)
		error("Bad number or parameters.");
	while (i < argc)
	{
		// ---------------- OPTION -DUMP ----------------------------
		if (ft_strcmp("-dump", argv[i]) == 0)
		{
			if ((i + 1 < argc) && !ft_isnumeric(argv[i + 1]))
				error("Expecting positive numeric value. (only numbers)");
			war->args->dump = ft_atoi(argv[i + 1]);
			i++;
		}
		// ----------------- OPTION -N ------------------------------
		else if (ft_strcmp("-n", argv[i]) == 0)
		{
			if ((i + 1 < argc) && !ft_isnumeric(argv[i + 1]))
				error("Expecting positive numeric value. (only numbers)");
			if ((i + 2 < argc) && ft_strstr(argv[i + 2], ".cor") != NULL)
			champ = init_champ(ft_atoi(argv[i + 1]));
			pile_append(war->pile_champ, champ);
			war->args->nb_champ++;
			i += 2;
		}
		// ---------------- CHAMP.COR ONLY ---------------------------
		else if (ft_strstr(argv[i], ".cor") != NULL)
		{
			pile_append(war->pile_champ, init_champ(3));//changer 3 par valeur 
//                                                                 disponible
			war->args->nb_champ++;
		}
		// --------------- WRONG COMMAND ------------------------------
		else
		{
			ft_putendl(argv[i]);
			error("Unrecognized command.");
		}
		i++;
	}
	if (war->args->nb_champ < 1 || war->args->nb_champ > 4)
		error("There must be between 1 and 4 players.");
	return (0);
}

int		main(int argc, char **argv)
{
	t_war	*war;
	t_args	args;
	t_node	*node;

	args.dump = -1;
	args.nb_champ = 0;
	war = init_war(&args);
	get_args(argc, argv, war);
	node = war->pile_champ->first;
	while (node)
	{
		printf("===> %x\n", node->champ->reg_tab[0]);
		node = node->next;
	}
}
