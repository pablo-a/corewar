#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/07 15:12:46 by vbarrete          #+#    #+#              #
#    Updated: 2016/06/17 19:48:48 by hdebard          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = asm

SRC = 	main.c\
		asm_parse_file.c\
		asm_check_file.c\
		asm_check_header.c\
		asm_check_label.c\
		asm_check_command.c\
		asm_check_command_2.c\
		asm_check_arg.c\
		asm_util.c\
		asm_strsplit.c\
		asm_encode.c\
		asm_find_command.c\
		asm_parse_command.c\
		asm_create_file.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		gcc -Wall -Werror -Wextra -o $(NAME) $(OBJ) -L libft/ -lft

$(OBJ): $(SRC)
		make -C libft/
		gcc -Wall -Wextra -Werror -I libft/ -c  $(SRC)

clean:
		make -C libft/ fclean
			rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

test: re
	./asm test.s
	cat test.cor

re: fclean all

special: all fclean

me: all clean