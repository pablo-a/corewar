/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 12:44:14 by pabril            #+#    #+#             */
/*   Updated: 2016/06/08 19:26:20 by pabril           ###   ########.fr       */
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
# include "../libft/includes/libftprintf.h"
# include "op.h"

# define bool	int
# define true	1
# define false	0

/* --------------------- STRUCTURE PRINCIPALE ---------------------------------
** CYCLE_TO_DIE est une variable centrale du jeu, on en aura besoin.
** les autres peuvent rester des define dans le op.h je pense
*/

typedef struct	s_env
{
	unsigned char	memory[MEM_SIZE];
	int				cycle_to_die;
}				t_env;

/* ------------------- STRUCTURE PROPRES AUX CHAMPIONS ------------------------
**       16 registres, un PC, un carry, son numero de joueur
*/

typedef struct	s_champ
{
	int		id;//num du champion, a mettre peut etre dans le env;
	int		reg_tab[REG_NUMBER];// ses registres
	int		PC;//                  prochaine instruction
	bool	carry;//               si operation a reussi ou pas.
}				t_champ;

typedef struct	s_op
{
	char	*name;
	int		nb_params;
	char	*params;
	int		opcode;
	int		nb_cycle;
	char	*description;
	bool	OCP;
	bool	modify_carry;
}				t_op;

#endif
