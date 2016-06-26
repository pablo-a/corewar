# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 18:38:06 by mcotfas           #+#    #+#              #
#    Updated: 2016/06/23 20:01:57 by pabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

INCLUDES =  -I ./includes/ -I ./libft/includes/
FTPATH = ./libft/
SRCSPATH = ./srcs/
INSTRUCTPATH = $(SRCSPATH)instructions/

SRCS = $(SRCSPATH)main.c \
	   $(SRCSPATH)champ.c \
	   $(SRCSPATH)launch_war.c \
	   $(SRCSPATH)handle_war.c \
	   $(SRCSPATH)pile.c \
	   $(SRCSPATH)init.c \
	   $(SRCSPATH)error.c \
	   $(SRCSPATH)calc_pc.c\
	   $(SRCSPATH)ncurse.c \
	   $(SRCSPATH)display_ncurse.c \
	   $(SRCSPATH)event_ncurse.c \
	   $(SRCSPATH)event_ncurse2.c \
	   $(SRCSPATH)refresh_ncurse.c \
	   $(SRCSPATH)get_ocp.c\
	   $(SRCSPATH)get_param.c\
	   $(SRCSPATH)def_opt.c\
	   $(SRCSPATH)define_params_types.c\
	   $(SRCSPATH)write_ram.c\
	   $(SRCSPATH)get_value.c \
	   $(SRCSPATH)copy_ram.c \
	   $(INSTRUCTPATH)add.c \
	   $(INSTRUCTPATH)aff.c \
	   $(INSTRUCTPATH)and.c \
	   $(INSTRUCTPATH)fork.c \
	   $(INSTRUCTPATH)ld.c \
	   $(INSTRUCTPATH)ldi.c \
	   $(INSTRUCTPATH)lfork.c \
	   $(INSTRUCTPATH)live.c \
	   $(INSTRUCTPATH)lld.c \
	   $(INSTRUCTPATH)lldi.c \
	   $(INSTRUCTPATH)or.c \
	   $(INSTRUCTPATH)st.c \
	   $(INSTRUCTPATH)sti.c \
	   $(INSTRUCTPATH)sub.c \
	   $(INSTRUCTPATH)xor.c \
	   $(INSTRUCTPATH)zjmp.c \

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libft re
	$(CC) -o $(NAME) $(OBJS) -L$(FTPATH) -lft -lncurses

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES)


clean :
	@$(RM) $(OBJS)
	@make -C ./libft clean
	$(RM) */*~ *~ \#* */\#*

fclean : clean
	@$(RM) $(NAME)
	@make -C ./libft fclean

re : fclean all

norme :
	norminette **/*.[ch]

.PHONY: re fclean clean all
