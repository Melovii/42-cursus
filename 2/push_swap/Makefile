NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address

RM = rm -fr

SRCS =	src/main.c		\
		# TODO: add the rest of the files
		libft/libft.a	\

# SRCS_BONUS =	src_bonus/checker_bonus.c	\
				# TODO: add the rest of the files
				libft/libft.a				\

$(NAME):
	make bonus -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

clean:
	$(RM) $(NAME)
	make clean -C libft

re: fclean all

# bonus:
	make bonus -C libft
	gcc $(CFLAGS) $(SRCS_BONUS) -o checker
