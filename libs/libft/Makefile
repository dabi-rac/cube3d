# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgasperi <sgasperi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 14:08:44 by sgasperi          #+#    #+#              #
#    Updated: 2024/06/07 13:59:22 by sgasperi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CHECKS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c

LST = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

MEM = ft_bzero.c ft_calloc.c ft_memchr.c ft_memdel.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c

MISC = ft_atoi.c ft_itoa.c ft_split.c ft_tolower.c ft_toupper.c

PUT = ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c

STR = ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c

SRC = $(addprefix input_check/, $(CHECKS)) \
		$(addprefix memory/, $(MEM)) \
		$(addprefix misc/, $(MISC)) \
		$(addprefix put_fd/, $(PUT)) \
		$(addprefix string_manipulation/, $(STR))

BONUS = $(addprefix lists/, $(LST))

OBJ = $(SRC:.c=.o)

OBJB = $(BONUS:.c=.o)

HDRS = libft.h

RM = rm -f

CC = gcc -Wall -Wextra -Werror

.c.o = ${CC} -I ${HDRS} includes -c $< -o ${<:.c=.o}

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

bonus: ${NAME} ${OBJB}
	ar rcs ${NAME} ${OBJB} ${OBJ}

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJB)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
