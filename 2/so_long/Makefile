# ! IMPORTANT:
# TODO: replace libraries with repos from intra42
# ! I mean bro dw, worst case scenario you add it as an external function and you can say oh uh look aha aha (sex)


# TODO: FIX
# ! fix: no player and no collectible (doesn't give error)
# ! fix: gives error when ran on correct maps multiple times (no clue why?)
# ! fix: doesn't work on map_eol.ber

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MINILIBX	= libs/minilibx-linux/libmlx_Linux.a
LIBFT		= libs/libft/libft.a

SRCS =	srcs/main.c			\
		srcs/exit.c			\
		srcs/parse.c		\
		srcs/check.c		\
		srcs/utils.c		\
		srcs/utils2.c		\

OBJS = $(SRCS:.c=.o)

all: default

default: $(NAME)

$(NAME): 	$(MINILIBX) $(LIBFT) $(GNL) $(OBJS)
			@$(CC) $(CFLAGS) $(OBJS)	\
			$(MINILIBX)					\
			$(LIBFT)					\
			$(GNL)						\
			-L./libs/minilibx-linux -lmlx -lX11 -lXext -lm -o $(NAME)
			@make clean
			@echo Makefile run successful!

# TODO: check if you need to include current directory for headers manually

%.o: %.c
		@$(CC) $(CFLAGS) -c					\
		-I./inc								\
		-I./libs/minilibx-linux $< -o $@	\
		-I./libs/libft						\
	

$(MINILIBX):
		@git clone https://github.com/42Paris/minilibx-linux.git libs/minilibx-linux
		@make -C libs/minilibx-linux

$(LIBFT):
		make -C libs/libft

$(GNL):

clean:
		@make fclean -C libs/libft
		rm -f $(OBJS)
	
fclean: clean
		@rm -fr $(NAME) libs/minilibx-linux

re: fclean all

.PHONY: all clean fclean re