# ! IMPORTANT:
# TODO: replace libraries with repos from intra42

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MINILIBX	= libs/minilibx-linux/libmlx_Linux.a
LIBFT		= libs/libft/libft.a
GNL			= libs/get_next_line/get_next_line.a

SRCS =	srcs/main.c			\
		srcs/test.c			\

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
		-I./libs/get_next_line				\
	

$(MINILIBX):
		@git clone https://github.com/42Paris/minilibx-linux.git libs/minilibx-linux
		@make -C libs/minilibx-linux

$(LIBFT):
		make -C libs/libft

$(GNL):
		make -C libs/get_next_line

clean:
		@make fclean -C libs/libft
		@make fclean -C libs/get_next_line
		rm -f $(OBJS)
	
fclean: clean
		@rm -fr $(NAME) libs/minilibx-linux

re: fclean all

.PHONY: all clean fclean re