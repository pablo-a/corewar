/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 21:45:57 by pabril            #+#    #+#             */
/*   Updated: 2016/06/24 20:03:41 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		read_instructions(int fd, t_champ *champ)
{
	unsigned char	c;
	int				i;

	i = 0;
	champ->instructions = (unsigned char *)malloc(CHAMP_MAX_SIZE);
	while (read(fd, &c, 1) > 0)
	{
		if (i > CHAMP_MAX_SIZE)
			error("Champion is too big!");
		(champ->instructions)[i] = c;
		i++;
	}
	return (0);
}

int		read_champ(char *file, t_champ *champ)
{
	t_header	*header;
	int			fd;

	if ((header = (t_header *)malloc(sizeof(t_header))) == NULL)
		perror_exit("Allocation failed :");
	if ((fd = open(file, O_RDONLY)) == -1)
		perror_exit("Open failed ");
	if ((size_t)read(fd, header, sizeof(t_header)) < sizeof(t_header))
		perror_exit("Read failed ");
	read_instructions(fd, champ);
	if (close(fd) == -1)
		perror_exit("Close failed ");
	header->magic = convert_to_big_endian(header->magic);
	header->prog_size = convert_to_big_endian(header->prog_size);
	if (header->magic != COREWAR_EXEC_MAGIC)
		error("Bad magic number.");
	champ->header = header;
	return (0);
}

int		count_processes_alive(t_war *war)
{
	t_node	*node;
	int		result;

	result = 0;
	node = war->pile_champ->first;
	while (node)
	{
		if (node->champ->is_dead == 0)
			result++;
		node = node->next;
	}
	return (result);
}

int		load_bytecode(t_champ *champ, t_war *war, int pos)
{
	unsigned int i;

	i = 0;
	while (i < champ->header->prog_size)
	{
		war->ram_info[i + pos] = -(champ->id);
		war->ram[i + pos] = champ->instructions[i];
//		war->ram2[i + pos] = champ->instructions[i];
		i++;
	}
	champ->op_cycles = get_nbr_cycle(war, pos);
	champ->op_next = war->ram[pos];
	return (0);
}

int		load_players_into_arena(t_war *war)
{
	t_node	*node;
	int		pos;
	int		space;

	pos = 0;
	node = war->pile_champ->first;
	space = MEM_SIZE / war->pile_champ->nb_elem;
	if (!war->args->ncurse)
		ft_printf("Introducing contestants :\n");
	while (node)
	{
		node->champ->pc = pos;
		load_bytecode(node->champ, war, pos);
		if (!war->args->ncurse)
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
ID(node->champ), SIZE(node->champ), NAME(node->champ), COMMENT(node->champ));
		node = node->next;
		pos += space;
	}
	return (0);
}
