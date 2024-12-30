# ! consider adding -l flag for when compiling (to include libft properly)
# TODO: fix building libft with default make 

NAME = pipex
CC = gcc
CFLAGS = -Werror -Wextra -Wall -fsanitize=address
RM = rm -fr
SRCS =	src/pipex.c			\
		src/pipex_utils.c		\
		libft/libft.a	\

# SRCS_BONUS =

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
