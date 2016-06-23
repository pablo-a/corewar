/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 00:15:14 by pabril            #+#    #+#             */
/*   Updated: 2016/06/23 16:54:57 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		convert_to_big_endian(unsigned int data)
{
	int result;

	result = ((data >> 24) & 0xFF) |
			((data >> 8) & 0xFF00) |
			((data << 8) & 0xFF0000) |
			((data << 24) & 0xFF000000);
	return (result);
}

int		who_won(t_war *war)
{
	t_node	*node;
	t_champ	*winner;
	int		i;

	i = 0;
	node = war->pile_champ->first;
	winner = war->pile_champ->first->champ;
	while (i < war->args->nb_champ)
	{
		if (node->champ->player->last_live > winner->player->last_live)
			winner = node->champ;
		node = node->next;
		i++;
	}
	if (war->args->ncurse)
	{
		mvwprintw(INFO_WINDOW, 4, 5, "Contestant %d, ", winner->id);
		put_good_color(INFO_WINDOW, -winner->id);
		mvwprintw(INFO_WINDOW, 4, 20, "%s", winner->header->prog_name);
		reset_colors(INFO_WINDOW);
		mvwprintw(INFO_WINDOW, 5, 5, "has won! Last live : %d ",
				winner->player->last_live);
		mvwprintw(INFO_WINDOW, 6, 5, "Press escape to leave");
		wrefresh(INFO_WINDOW);
		return (0);
	}
	ft_printf("Contestant %d, \"%s\" has won! Last live : %d \n", winner->id,
			winner->header->prog_name, winner->player->last_live);
	return (0);
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
			pile_append(war->pile_champ, init_champ(war->pile_champ->nb_elem
						+ 1));
			read_champ(argv[i], war->pile_champ->last->champ);
			war->args->nb_champ++;
		}
		// ---------------- NCURSE MODE -------------------------------
		else if (ft_strcmp("-ncurse", argv[i]) == 0)
			war->args->ncurse = 1;
		// ---------------- LIVE MODE ---------------------------------
		else if (ft_strcmp("-live", argv[i]) == 0)
			war->args->live = 1;
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

	args.dump = 0;
	args.ncurse = 0;
	args.nb_champ = 0;
	args.live = 0;
	war = init_war(&args);
	get_args(argc, argv, war);
	load_players_into_arena(war);
	if (war->args->ncurse == 1)
		init_ncurse(war);
	else
	{
		while (war->current_live_nb > 0)
		{
			launch_war(war);
		}
		who_won(war);
	}
	return (0);
}
