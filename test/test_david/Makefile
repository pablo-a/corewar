# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlouise <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/05 18:34:40 by dlouise           #+#    #+#              #
#    Updated: 2016/06/19 23:04:07 by hdebard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : fclean
.SUFFIXES :

LST = $(shell ls srcs)
SRC = $(addprefix srcs/, $(LST))
COR = $(SRC:.s=.cor)

all : fclean $(COR)

%.cor : %.s
	@mkdir -p our ref
	@cp $^ our/$(^:srcs/%=%)
	@cp $^ ref/$(^:srcs/%=%)
	@-../../asm our/$(^:srcs/%=%)
	@-./asm_zaz ref/$(^:srcs/%=%)
	@-hexdump our/$(@:srcs/%=%) > our/$(@:srcs/%=%).hex
	@-hexdump ref/$(@:srcs/%=%) > ref/$(@:srcs/%=%).hex
	@echo "\033[033m\c"
	@-diff ref/$(@:srcs/%=%).hex our/$(@:srcs/%=%).hex
	@echo "\033[0m\c"

fclean :
	@rm -rf ref
	@rm -rf our
