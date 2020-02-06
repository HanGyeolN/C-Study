# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hna <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/06 13:44:16 by hna               #+#    #+#              #
#    Updated: 2020/02/06 21:15:15 by hna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_tail
SRCS = ft_tail.c ft_get_filesize.c ft_is_dir.c
LIB_DIR = ./includes
HEADER_DIR = includes
OBJS = $(SRCS:%.c=%.o)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -L$(LIB_DIR) -lft_string -I $(HEADER_DIR)

all : $(NAME)

clean :

fclean : clean
	rm -f $(NAME)

re : fclean all
