# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hna <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 20:02:34 by hna               #+#    #+#              #
#    Updated: 2020/02/04 22:40:57 by hna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CFLAGS = -Wall -Wextra -Werror
SOURCES = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c \
		  srcs/ft_strlen.c srcs/ft_strcmp.c
OBJECTS = $(SOURCES:%.c=%.o)

$(NAME) : $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

all : $(NAME)

$(OBJECTS) : $(SOURCES)
	gcc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all
