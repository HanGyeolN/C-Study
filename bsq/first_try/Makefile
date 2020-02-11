NAME = bsq
CFLAGS = -Wall -Werror -Wextra
SRCS = *.c
LIB = ft_string
LIB_DIR = libs

$(NAME) :
	gcc $(CFLAGS) $(SRCS) -L./$(LIB_DIR) -l$(LIB) -o $(NAME) -I $(LIB_DIR)

all : $(NAME)

clean :

fclean : clean
	rm $(NAME)

re : fclean all
