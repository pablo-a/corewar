#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbarrete <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/07 15:12:46 by vbarrete          #+#    #+#              #
#    Updated: 2016/06/12 01:05:34 by hdebard          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = asm

SRC = 	main.c\
		asm_parse_file.c\
		asm_check_file.c\
		asm_check_header.c\
		asm_util.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		gcc -Wall -Werror -Wextra -o $(NAME) $(OBJ) -L libft/ -lft

$(OBJ): $(SRC)
		make -C libft/ fclean
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