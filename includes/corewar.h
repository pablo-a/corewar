/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 12:44:14 by pabril            #+#    #+#             */
/*   Updated: 2016/06/27 15:22:26 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <ncurses.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include "libftprintf.h"
# include "op.h"

# define RED "\033[31m"
# define BLACK "\033[30m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define GRAY "\033[37m"
# define YELLOW "\033[33m"
# define END "\033[0m"

# define MIN_HEIGHT 70
# define MIN_WIDTH 250
# define BYTE_PER_LINE 64
# define SPACE_BT_BYTE 1
# define SIZE_INFO 50
# define GAME_SPEED 10000

# define MAIN_WINDOW	war->ncurse->main_window
# define INFO_WINDOW	war->ncurse->info_window
# define EVENT_WINDOW	war->ncurse->event_window
# define PAUSE			war->ncurse->pause
# define SCREEN_Y		war->ncurse->size_window[0]
# define SCREEN_X		war->ncurse->size_window[1]

# define NAME(champ) champ->header->prog_name
# define COMMENT(champ) champ->header->comment
# define SIZE(champ) champ->header->prog_size
# define ID(champ) champ->id

# define USAGE "Usage: ./corewar [-dump nbr_cycles] [[-n number]champion1.cor]"
# define MYBOOL	int
# define TRUE	1
# define FALSE	0

/*
** --------------------- STRUCTURE PRINCIPALE ---------------------------------
** CYCLE_TO_DIE est une variable centrale du jeu, on en aura besoin.
** les autres peuvent rester des define dans le op.h je pense
*/

typedef struct	s_war
{
	unsigned char	ram[MEM_SIZE];
	unsigned char	ram2[MEM_SIZE];
	int				ram_info[MEM_SIZE];
	int				cycle_to_die;
	int				max_check;
	int				current_cycle;
	int				current_live_nb;
	struct s_op		*op_tab;
	struct s_args	*args;
	struct s_pile	*pile_champ;
	struct s_ncurse	*ncurse;
}				t_war;

/*
** ------------------- STRUCTURE PROPRES AUX CHAMPIONS ------------------------
**       16 registres, un PC, un carry, son numero de joueur
*/

typedef struct	s_player
{
	int		is_dead;
	int		last_live;
	int		nbr_live;
	int		current_nbr_live;
	int		id;
}				t_player;

typedef struct	s_champ
{
	struct s_player	*player;
	int				id;
	int				id_process;
	int				reg_tab[REG_NUMBER];
	int				pc;
	int				tmp_pc;
	MYBOOL			carry;
	int				cpt_interne;
	int				cpt_live[2];
	unsigned char	*instructions;
	t_header		*header;
	int				is_dead;
	int				op_cycles;
	int 			op_next;
}				t_champ;

/*
** ----------------------- STRUCTURE D'UNE PILE -------------------------------
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

/*
** --------------------- STRUCTURE DES INSTRUCTIONS AUTORISEES ----------------
** contient toutes les infos liees a chaque instructions. ptr sur fct a rajouter
*/

typedef struct	s_op
{
	char	name[5];
	int		nb_params;
	int		params[3];
	int		ocpode;
	int		nb_cycle;
	char	description[42];
	MYBOOL	ocp;
	MYBOOL	modify_carry;
	int		(*associated_function)(t_war *war, t_champ *champ);
}				t_op;

/*
** ------------------ STRUCTURE DES PARAMETRES --------------------------------
** va permettre de stocker les valeurs des parametres, si on veut ajouter des
**                        options ce sera ici
*/

typedef struct	s_args
{
	ssize_t	dump;
	int		nb_champ;
	int		ncurse;
	int		live;
}				t_args;

typedef struct	s_return
{
	int value;
	int error;
}				t_return;

/*
** ------------------ NCURSE STRUCT -----------------------------------------
*/

typedef struct	s_ncurse
{
	WINDOW	*main_window;
	WINDOW	*info_window;
	WINDOW	*event_window;
	int		size_window[2];
	int		game_speed;
	int		cycle_per_sec;
	int		pause;
}				t_ncurse;

typedef struct	s_ocp
{
	int		first;
	int		second;
	int		third;
	int		fourth;
}				t_ocp;

typedef struct	s_param_opt
{
	int		is_index;
	int		reg_value;
	int		add_value;
}				t_param_opt;

typedef struct	s_params
{
	int					reg;
	int					direct;
	int					indirect;
	struct s_param_opt	opt;
}				t_params;

/*
** --------------------- FONCTIONS PROTOTYPES --------------------------------
*/
void 			copy_ram(unsigned char ram[MEM_SIZE], unsigned char ram2[MEM_SIZE]);

t_pile			*new_pile(void);
int				pile_append(t_pile *pile, t_champ *champ);
int				pile_prepend(t_pile *pile, t_champ *champ);
int				free_pile(t_pile **pile);

t_champ			*init_champ(ssize_t id);
t_op			*init_op_tab(void);
t_war			*init_war(t_args *args);

int				read_champ(char *file, t_champ *champ);
int				read_instructions(int fd, t_champ *champ);
int				load_players_into_arena(t_war *war);
int				load_bytecode(t_champ *champ, t_war *war, int pos);

int				convert_to_big_endian(unsigned int data);
int				who_won(t_war *war);
int				sub_get_args(int argc, char **argv, t_war *war, int i);
int				get_args(int argc, char **argv, t_war *war);
int				main(int argc, char **argv);

int				error(char *str);
int				perror_exit(char *error);
int				display_ram(unsigned char ram[MEM_SIZE],
														int ram_info[MEM_SIZE]);
int				display_ram_info(int ram_info[MEM_SIZE]);
int				display_reg(t_champ *champ);

int				reset_champ_live(t_war *war);
int				find_dead_champs(t_war *war);
int				dump_war(t_war *war);
int				get_nbr_cycle(t_war *war, int pc);
int				handle_cycle_to_die(t_war *war);

int				get_proc_alive(t_war *war);
int				execute(t_war *war, t_champ *champ);
int				champ_action(t_war *war);
int				launch_war(t_war *war);

int				calc_pc(int pc, int value);
t_ocp			get_ocp(int value);
t_params		define_params_types(int type1, int type2, int type3,
									t_param_opt opt);
t_return		get_param(t_war *war, t_params params, int param_nb,
									t_champ *champ);
t_param_opt		def_opt(int is_index, int reg_value, int add_value);
void			write_ram(t_war *war, t_champ *champ, int value, int address);

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

/*
** -------------------------- NCURSE PART -------------------------------------
*/

int				set_colors(void);
int				put_good_color(WINDOW *win, int color);
int				check_size_window(t_war *war);
int				init_ncurse_struct(t_war *war);
int				init_ncurse(t_war *war);

void			display_pc(t_war *war);
void			display_infos(WINDOW *win, t_war *war);
void			display_main_content(WINDOW *win, t_war *war);
int				display_champs(t_war *war, WINDOW *win, int *y, int *x);
void			draw_borders(WINDOW *screen);

int				refresh_current_cycle(t_war *war);
int				refresh_pc(t_war *war, t_champ *champ, int old_pc, int new_pc);
int				erase_pc(t_war *war, t_champ *champ, int pc);
int				refresh_info_constants(t_war *war);
int				refresh_lives_info(t_war *war);
int				refresh_ram(t_war *war, int pos, int size, int color);

int				event_ncurse2(t_war *war, int ch);

int				event(t_war *war, int no_delay);
int				bad_size_window(int y, int x);
int				calc_pos_in_ram(int *y, int *x, int size_window[2], int pos);
int				reset_colors(WINDOW *win);

#endif
