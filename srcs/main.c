/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 00:15:14 by pabril            #+#    #+#             */
/*   Updated: 2016/06/10 13:54:16 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include "libftprintf.h"


int		convert_to_big_endian(unsigned int data)
{
	int result;

	result = ((data>>24) & 0xFF) |
			((data>>8) & 0xFF00) |
			((data<<8) & 0xFF0000) |
			((data<<24) & 0xFF000000);
	return (result);
}

int		read_header(char *file, t_champ *champ)
{
	t_header	*header;
	int			fd;

	if ((header = (t_header *)malloc(sizeof(t_header))) == NULL)
		perror_exit("Allocation failed :");
	if ((fd = open(file, O_RDONLY)) == -1)
		perror_exit("Open failed ");
	if (read(fd, header, sizeof(t_header)) == -1)
		perror_exit("Read failed ");
	if (close(fd) == -1)
		perror_exit("Close failed ");
	header->magic = convert_to_big_endian(header->magic);
	header->prog_size = convert_to_big_endian(header->prog_size);
	printf("name: %s, comment: %s, magic: %#010x, size: %#010x\n", header->prog_name, header->comment, header->magic, header->prog_size);
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
			read_header(argv[i + 2], war->pile_champ->last->champ);
			war->args->nb_champ++;
			i += 2;
		}
		// ---------------- CHAMP.COR ONLY ---------------------------
		else if (ft_strstr(argv[i], ".cor") != NULL)
		{
			pile_append(war->pile_champ, init_champ(3));//changer 3 par valeur 
			read_header(argv[i], war->pile_champ->last->champ);
//                                                                 disponible
			war->args->nb_champ++;
		}
		// --------------- WRONG COMMAND ------------------------------
		else
		{
			ft_putendl(argv[i]);
			error("Unrecognized parameter.");
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
