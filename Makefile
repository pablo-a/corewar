# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 18:38:06 by mcotfas           #+#    #+#              #
#    Updated: 2016/03/25 19:40:23 by mcotfas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
CFLAGS = -Wall -Wextra -Werror
CC = gcc
OBJS = $(SRCS:.c=.o)
INCLUDES = ./includes/
FTPATH = ./libft/
SRCSPATH = ./srcs/
SRCS = $(SRCSPATH)main.c

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libft re
	$(CC) -o $(NAME) $(OBJS) -L$(FTPATH) -lft

%.o: %.c
		@$(CC) -o $@ -c $< $(CFLAGS) -I $(INCLUDES)

clean :
	@$(RM) $(OBJS)
	@make -C ./libft clean
	$(RM) */*~ *~ \#* */\#*

fclean : clean
	@$(RM) $(NAME)
	@make -C ./libft fclean

re : fclean all

.PHONY: re fclean clean all