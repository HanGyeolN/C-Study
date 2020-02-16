# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hna <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 20:02:34 by hna               #+#    #+#              #
#    Updated: 2020/02/04 20:32:08 by hna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
HEADER = includes/ft.h
SOURCES = $(SRC_DIR)/ft_putchar.c $(SRC_DIR)/ft_swap.c $(SRC_DIR)/ft_putstr.c \
		  $(SRC_DIR)/ft_strlen.c $(SRC_DIR)/ft_strcmp.c
OBJECTS = $(SOURCES:%.c=%.o)

$(NAME) : $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

all : $(NAME)

ft_putchar.o : srcs/ft_putchar.c
	gcc $(CFLAGS) -c $(SRC_DIR)/ft_putchar.c $(HEADER) -o srcs/ft_putchar.o 

ft_swap.o : srcs/ft_swap.c
	gcc $(CFLAGS) -c $(SRC_DIR)/ft_swap.c $(HEADER) -o srcs/ft_swap.o

ft_putstr.o : srcs/ft_putstr.c
	gcc $(CFLAGS) -c $(SRC_DIR)/ft_putstr.c $(HEADER) -o srcs/ft_putstr.o

ft_strlen.o : srcs/ft_strlen.c
	gcc $(CFLAGS) -c $(SRC_DIR)/ft_strlen.c $(HEADER) -o srcs/ft_strlen.o

ft_strcmp.o : srcs/ft_strcmp.c
	gcc $(CFLAGS) -c $(SRC_DIR)/ft_strcmp.c $(HEADER) -o srcs/ft_strcmp.o

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all
