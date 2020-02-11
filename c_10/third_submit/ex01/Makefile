# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hna <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/05 20:08:51 by hna               #+#    #+#              #
#    Updated: 2020/02/11 22:50:45 by hna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = ft_cat
CFLAGS = -Wall -Wextra -Werror
HEADER_DIR = includes
SRC_IDR = srcs
LIB_DIR = libs
LIB_FILE = libft_string.a
LIB = ft_putchar.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_strcat.c \
		ft_strcpy.c \
		ft_string.h \
		ft_strlen.c
SRC = ft_cat.c ft_init_str.c ft_file.c

LIBS = $(addprefix $(LIB_DIR)/, $(LIB))
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

$(NAME) : $(SRCS) $(LIB_FILE)
	$(CC) $(CFLAGS) $(SRCS) -L./$(LIB_DIR) -lft_string -o $(NAME) -I $(HEADER_DIR)

$(LIB_FILE) : $(LIBS)
	ar rc $(LIB_DIR)/$(LIB_FILE) $(LIBS)

srcs : 
	$(info $(SRCS))

libs :
	$(info $(LIBS))

all : $(NAME)

clean : 

fclean : clean
	rm -f $(NAME)

re : fclean all
