NAME= minishell
SRC= minishell.c
SRCPATH= ./cfiles/
OBJ= $(SRC:.c=.o)
OBJS= $(addprefix $(OBJPATH), $(OBJ))
SRCS= $(addprefix $(SRCPATH), $(SRC))
OBJPATH= ./ofiles/

CC= gcc -Wall -Wextra -Werror

all: makelib $(NAME)

makelib:
	make -C ./libft2

$(OBJPATH)%.o: $(SRCPATH)%.c
	mkdir -p ofiles
	$(CC) -I./hfiles -I./libft2 -lreadfile -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -Llibft2 -lft -L/usr/lib -I./libft2 -I./hfiles -lreadline

clean:
	rm -f $(OBJS)
	rm -rf ofiles
	make clean -C ./libft2

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft2

re: fclean all
