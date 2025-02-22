# ! IMPORTANT:
# TODO: replace libraries with repos from intra42
# ! I mean bro dw, worst case scenario you add it as an external function and you can say oh uh look aha aha (sex)
# ? do I check to replace get_next_line or at least put it somwhere else?
# ! add the header files WHILE IN 42

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
# CFLAGS		= -g
MINILIBX	= libs/minilibx-linux/libmlx_Linux.a
LIBFT		= libs/libft/libft.a

SRCS =	srcs/main.c			\
		srcs/exit.c			\
		srcs/parse.c		\
		srcs/check.c		\
		srcs/keys.c			\
		srcs/draw.c			\
		srcs/textures.c		\
		srcs/game_logic.c	\
		srcs/validation.c	\

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