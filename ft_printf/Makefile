# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 04:36:36 by esttina           #+#    #+#              #
#    Updated: 2025/12/04 21:14:18 by esttina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

all: ${NAME}

SRCS = ft_printf.c char_specifier.c num_specifier.c hex_specifier.c

OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = cc

%.o: %.c ft_printf.h
	${CC} ${FLAGS} -c $< -o $@

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -rf ${OBJECTS}

fclean:	clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re