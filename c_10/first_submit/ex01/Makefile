# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hna <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/05 20:08:51 by hna               #+#    #+#              #
#    Updated: 2020/02/06 20:15:36 by hna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = ft_cat
CFLAGS = -Wall -Wextra -Werror
HEADER_DIR = includes
LIB_DIR = ./includes
LIB_FILE = libft_string.a
SRCS = ft_cat.c ft_is_dir.c ft_init_str.c ft_get_filesize.c

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -L$(LIB_DIR) -lft_string -o $(NAME) -I $(HEADER_DIR)

all : $(NAME)

clean : 

fclean : clean
	rm -f $(NAME)

re : fclean all
