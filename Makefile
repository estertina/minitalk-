# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/17 21:00:04 by esttina           #+#    #+#              #
#    Updated: 2026/03/14 05:20:43 by esttina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJ_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJ_SERVER = $(SRCS_SERVER:.c=.o)

INCLUDES = -I. -I$(PRINTF_DIR)

FLAGS = -Wall -Wextra -Werror

CC = cc

all: $(PRINTF) $(NAME_CLIENT) $(NAME_SERVER)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(FLAGS) $(OBJ_CLIENT) $(PRINTF) -o $(NAME_CLIENT) 

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(FLAGS) $(OBJ_SERVER) $(PRINTF) -o $(NAME_SERVER)

%.o: %.c minitalk.h
	${CC} ${FLAGS} $(INCLUDES) -c $< -o $@

clean:
	rm -rf ${OBJ_CLIENT} ${OBJ_SERVER}
	$(MAKE) -C $(PRINTF_DIR) clean

fclean:	clean
	rm -rf ${NAME_CLIENT} ${NAME_SERVER}
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re