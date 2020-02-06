# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hna <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/05 21:35:19 by hna               #+#    #+#              #
#    Updated: 2020/02/06 11:43:27 by hna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft_string.a
CFLAGS = -Wall -Werror -Wextra
SRCS = *.c
OBJS = $(SRCS:%.c=%.o)

$(NAME) : $(OBJS)
	ar rc ../$(NAME) $(OBJS)
	cp ft_string.h ../ft_string.h

%.o : %.c
	gcc $(CFLAGS) -c $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f ../$(NAME)

re : fclean all
