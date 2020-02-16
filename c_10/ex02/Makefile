# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hna <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/06 13:44:16 by hna               #+#    #+#              #
#    Updated: 2020/02/10 21:02:28 by hna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_tail
SRCS = ft_atoi.c ft_init_str.c ft_file.c ft_tail.c main.c
LIB = ft_string
LIB_DIR = libs
HEADER_DIR = includes
OBJS = $(SRCS:%.c=%.o)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -L./$(LIB_DIR) -l$(LIB) -I $(HEADER_DIR)

all : $(NAME)

clean :

fclean : clean
	rm -f $(NAME)

re : fclean all
