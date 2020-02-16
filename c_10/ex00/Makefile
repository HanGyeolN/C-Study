CC = gcc
NAME = ft_display_file
CFLAGS = -Wall -Werror -Wextra
HEADER_DIR = includes
LIB_DIR = ./includes
SRCS = srcs/ft_display_file.c srcs/main.c
OBJS = $(SRCS:%.c=%.o)

$(NAME) : includes/libft.a includes/ft.h
	$(CC) $(CFLAGS) $(SRCS) -L$(LIB_DIR) -lft -I $(HEADER_DIR) -o $(NAME)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
