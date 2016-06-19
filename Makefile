#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/07 15:12:46 by vbarrete          #+#    #+#              #
#    Updated: 2016/06/19 23:03:26 by hdebard          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = asm

SRC = 	sources/main.c\
		sources/parsing/asm_parse_file.c\
		sources/parsing/asm_check_file.c\
		sources/parsing/asm_check_header.c\
		sources/parsing/asm_check_label.c\
		sources/parsing/asm_check_command.c\
		sources/parsing/asm_command_1.c\
		sources/parsing/asm_command_2.c\
		sources/parsing/asm_check_arg.c\
		sources/util/asm_util.c\
		sources/util/asm_strsplit.c\
		sources/encoding/asm_encode.c\
		sources/encoding/asm_find_command.c\
		sources/encoding/asm_parse_command.c\
		sources/writing/asm_create_file.c\
		sources/util/asm_debug.c

OBJ = 	main.o\
		asm_parse_file.o\
		asm_check_file.o\
		asm_check_header.o\
		asm_check_label.o\
		asm_check_command.o\
		asm_command_1.o\
        asm_command_2.o\
        asm_check_arg.o\
        asm_util.o\
        asm_strsplit.o\
        asm_encode.o\
        asm_find_command.o\
        asm_parse_command.o\
        asm_create_file.o\
        asm_debug.o

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