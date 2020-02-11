CC = gcc
NAME = ft_display_file
CFLAGS = -Wall -Werror -Wextra
HEAD_DIR = includes
SRC = ft_display_file.c
SRC_DIR = srcs

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(SRCS:%.c=%.o)

$(NAME) :
	$(CC) $(CFLAGS) $(SRCS) -I $(HEAD_DIR) -o $(NAME)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
