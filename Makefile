# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 18:38:06 by mcotfas           #+#    #+#              #
#    Updated: 2016/06/08 23:44:10 by pabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

CC = gcc
CFLAGS = -Wall -Wextra

OBJS = $(SRCS:.c=.o)

INCLUDES = ./includes/
FTPATH = ./libft/
SRCSPATH = ./srcs/
INSTRUCTPATH = $(SRCSPATH)instructions/

SRCS = $(SRCSPATH)main.c \
	   $(SRCSPATH)pile.c \
	   $(SRCSPATH)init.c \
	   $(SRCSPATH)error.c \
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
	$(CC) -o $(NAME) $(OBJS) -L$(FTPATH) -lft 
%.o: %.c
		@$(CC) -o $@ -c $< $(CFLAGS) -I $(INCLUDES) -I ./libft/includes/


clean :
	@$(RM) $(OBJS)
	@make -C ./libft clean
	$(RM) */*~ *~ \#* */\#*

fclean : clean
	@$(RM) $(NAME)
	@make -C ./libft fclean

re : fclean all

.PHONY: re fclean clean all
