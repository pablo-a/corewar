/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 12:44:14 by pabril            #+#    #+#             */
/*   Updated: 2016/06/15 17:07:03 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

/* On va pouvoir utiliser ERRNO c'est de la balle :
** if (malloc(...) == -1)
**		ft_printf("erreur : %s\n", strerror(errno)); || perror("Erreur:");
*/
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include "libftprintf.h"
# include "ncurses.h"
# include "op.h"

# define RED "\033[31m"
# define BLACK "\033[30m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define GRAY "\033[37m"
# define YELLOW "\033[33m"
# define END "\033[0m"

# define NAME(champ) champ->header->prog_name
# define COMMENT(champ) champ->header->comment
# define SIZE(champ) champ->header->prog_size
# define ID(champ) champ->id

# define USAGE "Usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ..."
# define bool	int
# define true	1
# define false	0

/* --------------------- STRUCTURE PRINCIPALE ---------------------------------
** CYCLE_TO_DIE est une variable centrale du jeu, on en aura besoin.
** les autres peuvent rester des define dans le op.h je pense
*/

typedef struct	s_war
{
	unsigned char	ram[MEM_SIZE];
	int				cycle_to_die;
	int				max_check;
	int				current_cycle;
	int				current_live_nb;
	struct s_op		*op_tab;
	struct s_args	*args;
	struct s_pile	*pile_champ;
}				t_war;

/* ------------------- STRUCTURE PROPRES AUX CHAMPIONS ------------------------
**       16 registres, un PC, un carry, son numero de joueur
*/
typedef struct	s_champ
{
	int				id;//num du champion, a mettre peut etre dans le env;
	int				reg_tab[REG_NUMBER];// ses registres
	int				pc;//                  prochaine instruction
	bool			carry;//               si operation a reussi ou pas.
	int				cpt_interne;// pour faire ses operations. (cycles).
	int				cpt_live[2];// cpt[1] = nb_live et cpt[2] = last_live;
	unsigned char	*instructions;
	t_header		*header;
	struct s_champ	*father;
	int				is_dead;
}				t_champ;

/* ----------------------- STRUCTURE D'UNE PILE -------------------------------
**
*/

typedef struct	s_pile
{
	int				nb_elem;
	struct s_node	*first;
	struct s_node	*last;
}				t_pile;

typedef struct	s_node
{
	struct s_champ	*champ;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

/* --------------------- STRUCTURE DES INSTRUCTIONS AUTORISEES ----------------
** contient toutes les infos liees a chaque instructions. ptr sur fct a rajouter
*/

typedef struct	s_op
{
	char	name[5];
	int		nb_params;
	int		params[3];
	int		opcode;
	int		nb_cycle;
	char	description[42];
	bool	ocp;
	bool	modify_carry;
	int		(*associated_function)(t_war *war, t_champ *champ);
}				t_op;

/* ------------------ STRUCTURE DES PARAMETRES --------------------------------
** va permettre de stocker les valeurs des parametres, si on veut ajouter des
**                        options ce sera ici
*/

typedef struct	s_args
{
	ssize_t	dump;
	int		nb_champ;
}				t_args;


typedef struct	s_return
{
	int value;
	int error;
}				t_return;
/*
** --------------------- FONCTIONS PROTOTYPES --------------------------------
*/

t_pile			*new_pile(void);
int				pile_append(t_pile *pile, t_champ *champ);
int				pile_prepend(t_pile *pile, t_champ *champ);//     PILE.C
int				free_pile(t_pile **pile);

t_champ			*init_champ(ssize_t id);
t_op			*init_op_tab(void);//                            INIT.C
t_war			*init_war(t_args *args);

int				read_champ(char *file, t_champ *champ);
int				read_instructions(int fd, t_champ *champ);//  CHAMP.C
int				load_players_into_arena(t_war *war);
int				load_bytecode(t_champ *champ, unsigned char ram[MEM_SIZE],
				int pos);

int				convert_to_big_endian(unsigned int data);
int				get_args(int argc, char **argv, t_war *war);//     MAIN.C
int				main(int argc, char **argv);

int				error(char *str);//                                  ERROR.C
int				perror_exit(char *error);
int				display_ram(unsigned char ram[MEM_SIZE]);
int				display_reg(t_champ *champ);

int				reset_champ_live(t_war *war);
int				find_dead_champs(t_war *war);
int				champ_action(t_war *war);//      LAUNCH_WAR.C
int				dump_war(t_war *war);
int				launch_war(t_war *war);

int 			calc_pc(int pc, int value);

int				get_value(t_war *war, int pos, int size);
int				add(t_war *war, t_champ *champ);
int				aff(t_war *war, t_champ *champ);
int				and(t_war *war, t_champ *champ);
int				cor_fork(t_war *war, t_champ *champ);
int				ld(t_war *war, t_champ *champ);
int				ldi(t_war *war, t_champ *champ);
int				lfork(t_war *war, t_champ *champ);
int				live(t_war *war, t_champ *champ);
int				lld(t_war *war, t_champ *champ);
int				lldi(t_war *war, t_champ *champ);
int				or(t_war *war, t_champ *champ);
int				st(t_war *war, t_champ *champ);
int				sti(t_war *war, t_champ *champ);
int				sub(t_war *war, t_champ *champ);
int				xor(t_war *war, t_champ *champ);
int				zjmp(t_war *war, t_champ *champ);

#endif
