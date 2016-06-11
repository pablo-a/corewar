/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 00:15:14 by pabril            #+#    #+#             */
/*   Updated: 2016/06/11 12:43:03 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libftprintf.h"

int		convert_to_big_endian(unsigned int data)
{
	int result;

	result = ((data >> 24) & 0xFF) |
			((data >> 8) & 0xFF00) |
			((data << 8) & 0xFF0000) |
			((data << 24) & 0xFF000000);
	return (result);
}

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
			if ((i + 1 >= argc) || !ft_isnumeric(argv[i + 1]))
				error("Expecting positive numeric value. (only numbers)");
			war->args->dump = ft_atoi(argv[i + 1]);
			i++;
		}
		// ----------------- OPTION -N ------------------------------
		else if (ft_strcmp("-n", argv[i]) == 0)
		{
			if ((i + 1 >= argc) || !ft_isnumeric(argv[i + 1]))
				error("Expecting positive numeric value. (only numbers)");
			if ((i + 2 >= argc) || ft_strstr(argv[i + 2], ".cor") == NULL)
				error("Expecting a player file. (*.cor) ");
			champ = init_champ(ft_atoi(argv[i + 1]));
			pile_append(war->pile_champ, champ);
			read_champ(argv[i + 2], war->pile_champ->last->champ);
			war->args->nb_champ++;
			i += 2;
		}
		// ---------------- CHAMP.COR ONLY ---------------------------
		else if (ft_strstr(argv[i], ".cor") != NULL)
		{
			pile_append(war->pile_champ, init_champ(war->pile_champ->nb_elem + 1
						));
			read_champ(argv[i], war->pile_champ->last->champ);
			war->args->nb_champ++;
		}
		// --------------- WRONG COMMAND ------------------------------
		else
			error("Unrecognized parameter.");
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

	args.dump = -1;
	args.nb_champ = 0;
	war = init_war(&args);
	get_args(argc, argv, war);
	load_players_into_arena(war);
	display_ram(war->ram);
	while (war->current_live_nb > 0)
		launch_war(war);
	return (0);
}
