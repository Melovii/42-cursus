CC		= cc
CFLAGS	= -Wall -Wextra -Werror

NAME = get_next_line.a

SRCS =	get_next_line.c				\
		get_next_line_utils.c		\
		get_next_line_bonus.c		\
		get_next_line_utils_bonus.c	\
		
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
