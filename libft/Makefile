# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 18:38:06 by mcotfas           #+#    #+#              #
#    Updated: 2016/06/10 10:55:27 by pabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
INCLUDES = ./includes/
OBJS = $(SRCS:.c=.o)
FTPATH = ./libft/
PRINTFPATH = ./libftprintf/
SRCS = $(FTPATH)ft_putchar.c \
				$(FTPATH)ft_putchar_fd.c \
				$(FTPATH)ft_putstr.c \
				$(FTPATH)ft_putstr_fd.c \
				$(FTPATH)ft_putnbr.c \
				$(FTPATH)ft_putnbr_fd.c \
				$(FTPATH)ft_strlen.c \
				$(FTPATH)ft_strcpy.c \
				$(FTPATH)ft_strncpy.c \
				$(FTPATH)ft_memalloc.c \
				$(FTPATH)ft_strnew.c \
				$(FTPATH)ft_putendl.c \
				$(FTPATH)ft_putendl_fd.c \
				$(FTPATH)ft_memdel.c \
				$(FTPATH)ft_strdel.c \
				$(FTPATH)ft_strclr.c \
				$(FTPATH)ft_strcmp.c \
				$(FTPATH)ft_strncmp.c \
				$(FTPATH)ft_strequ.c \
				$(FTPATH)ft_strnequ.c \
				$(FTPATH)ft_strstr.c \
				$(FTPATH)ft_strnstr.c \
				$(FTPATH)ft_strdup.c \
				$(FTPATH)ft_strchr.c \
				$(FTPATH)ft_strrchr.c \
				$(FTPATH)ft_isdigit.c \
				$(FTPATH)ft_isalpha.c \
				$(FTPATH)ft_isalnum.c \
				$(FTPATH)ft_isascii.c \
				$(FTPATH)ft_isprint.c \
				$(FTPATH)ft_isnumeric.c \
				$(FTPATH)ft_toupper.c \
				$(FTPATH)ft_tolower.c \
				$(FTPATH)ft_memset.c \
				$(FTPATH)ft_bzero.c \
				$(FTPATH)ft_memcpy.c \
				$(FTPATH)ft_memccpy.c \
				$(FTPATH)ft_memmove.c \
				$(FTPATH)ft_memchr.c \
				$(FTPATH)ft_memcmp.c \
				$(FTPATH)ft_strcat.c \
				$(FTPATH)ft_strncat.c \
				$(FTPATH)ft_strlcat.c \
				$(FTPATH)ft_striter.c \
				$(FTPATH)ft_striteri.c \
				$(FTPATH)ft_strjoin.c \
				$(FTPATH)ft_strjoin_free.c \
				$(FTPATH)ft_strmap.c \
				$(FTPATH)ft_strmapi.c \
				$(FTPATH)ft_strsplit.c \
				$(FTPATH)ft_strsub.c \
				$(FTPATH)ft_strtrim.c \
				$(FTPATH)ft_atoi.c \
				$(FTPATH)ft_itoa.c \
				$(FTPATH)ft_isspace.c \
				$(FTPATH)ft_absvalue.c \
				$(FTPATH)ft_lstnew.c \
				$(FTPATH)ft_lstdelone.c \
				$(FTPATH)ft_lstdel.c \
				$(FTPATH)ft_lstadd.c \
				$(FTPATH)ft_lstiter.c \
				$(FTPATH)ft_lstmap.c \
				$(FTPATH)ft_lstaddend.c \
				$(FTPATH)ft_lstsplit.c \
				$(FTPATH)ft_lstback.c \
				$(FTPATH)get_next_line.c \
				$(FTPATH)ft_itoa_base.c \
				$(FTPATH)ft_itoa_base_u.c \
				$(FTPATH)ft_bin_to_dec.c \
				$(FTPATH)ft_charstr.c \
				$(FTPATH)ft_str_is_int.c \
				$(PRINTFPATH)ft_printf.c \
				$(PRINTFPATH)build_info.c \
				$(PRINTFPATH)info_utils.c \
				$(PRINTFPATH)conv_arg.c \
				$(PRINTFPATH)conv_s.c \
				$(PRINTFPATH)conv_d.c \
                $(PRINTFPATH)conv_p.c \
                $(PRINTFPATH)conv_i.c \
                $(PRINTFPATH)conv_o.c \
                $(PRINTFPATH)conv_u.c \
                $(PRINTFPATH)conv_x.c \
                $(PRINTFPATH)conv_c.c \
                $(PRINTFPATH)conv_cc.c \
                $(PRINTFPATH)conv_dd.c \
                $(PRINTFPATH)conv_oo.c \
                $(PRINTFPATH)conv_ss.c \
                $(PRINTFPATH)conv_uu.c \
                $(PRINTFPATH)conv_xx.c \
                $(PRINTFPATH)transform_str.c \
                $(PRINTFPATH)transform_char.c \
                $(PRINTFPATH)free_info.c \
                $(PRINTFPATH)prec_nb.c \
                $(PRINTFPATH)print_buffer.c \
                $(PRINTFPATH)extract_nb_from_str.c

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
		@$(CC) -o $@ -c $< $(CFLAGS) -I $(INCLUDES)

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY: re fclean clean all
