CC := gcc
SRCDIR := cfiles
OBJDIR := ofiles
BINDIR := bin
INCDIR := hfiles
LIBFTDIR := libft2
NAME := minishell
TARGET := $(BINDIR)/$(NAME)
LIBFT := $(LIBFTDIR)/libft.a
SRC := $(wildcard $(SRCDIR)/**/*.c) $(wildcard $(SRCDIR)/*.c)
OBJ := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
FLAGS := -Wextra -Werror -Wall -O3
CFLAGS := $(FLAGS) -I$(INCDIR) -I$(LIBFTDIR)

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(LIBFT) $(OBJ)
	@mkdir -p $(BINDIR)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT) -lreadline > /dev/null
	@echo "$(NAME) successfully compiled in $(BINDIR)/"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -s -C $(LIBFTDIR)

clean:
	@$(MAKE) -s -C $(LIBFTDIR) clean
	@rm -rf $(OBJDIR)
	@rm -rf $(BINDIR)

fclean: clean
	@$(MAKE) -s -C $(LIBFTDIR) fclean

re: fclean all
