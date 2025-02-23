# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
DEBUG = -g

# Project
NAME = pipex
SRC = pipex.c utils.c
# BONUS = pipex_bonus.c u_pipex_bonus.c ../libft/get_next_line.c u_pipex.c
OBJ = $(SRC:.c=.o)
# B_OBJ = $(BONUS:.c=.o)
LIBFT = ../libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C ../libft

clean:
	rm -f $(OBJ)
	make -C ../libft clean

fclean: clean
	rm -f $(NAME)
	make -C ../libft fclean

re: fclean all

.PHONY: all bonus clean fclean re