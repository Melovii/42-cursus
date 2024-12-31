# ! consider adding -l flag for when compiling (to include libft properly)
# TODO: fix relinking (research this topic)
# ? understand -C flag on a deep level

NAME = pipex

CC = gcc

CFLAGS = -Werror -Wextra -Wall -fsanitize=address # ? should I keep -fsanitize ?

RM = rm -fr

SRCS =	src/pipex.c			\
		src/pipex_utils.c	\
		libft/libft.a		\

# SRCS_BONUS =	bonus/pipex_bonus.c			\
				bonus/pipex_utils_bonus.c	\
				libft/libft.a				\

$(NAME): $(SRCS)
	make all -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

clean:
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

bonus: clean
	make all -C libft
	gcc $(CFLAGS) $(SRCS_BONUS) -o $(NAME)
