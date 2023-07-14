NAME= minishell
SRC= minishell.c ms_parsing1.c ms_parsing2.c ms_parsing_utils.c ms_error.c ms_export.c ms_env_utils.c ms_env.c ms_unset.c ms_command_utils.c ms_pwd.c ms_cd.c ms_echo.c ms_redir.c
SRCPATH= ./cfiles/
OBJ= $(SRC:.c=.o)
OBJS= $(addprefix $(OBJPATH), $(OBJ))
SRCS= $(addprefix $(SRCPATH), $(SRC))
OBJPATH= ./ofiles/

CC= gcc #-Wall -Wextra -Werror

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
