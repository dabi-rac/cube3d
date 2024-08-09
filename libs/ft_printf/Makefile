# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 10:00:00 by sgasperi          #+#    #+#              #
#    Updated: 2023/02/21 09:30:59 by sgasperi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_putchar.c \
	  ft_putnbr.c \
	  ft_putnbr_hex.c \
	  ft_putnbr_hex_address.c \
	  ft_putnbr_paddress.c \
	  ft_putnbr_uns.c \
	  ft_putstr.c \
	ft_printf.c \

OBJ = $(SRC:.c=.o)

HDRS = ft_printf.h

RM = rm -f

CC = gcc -Wall -Wextra -Werror

.c.o = ${CC} -I ${HDRS} includes -c $< -o ${<:.c=.o}

%.o: %.c
	@gcc ${FLAG} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
	@ar rcs ${NAME} ${OBJ}
	@ranlib ${NAME}

clean:
	@rm -f ${OBJ}

fclean: clean
		@rm -f ${NAME}

re: fclean all

.PHONY: all, clean, fclean, re
