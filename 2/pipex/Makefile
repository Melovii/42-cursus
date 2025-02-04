NAME = pipex

CC = gcc
CFLAGS = -Werror -Wextra -Wall
RM = rm -fr

# List your source files
SRCS = src/pipex.c src/pipex_utils.c

# Generate object file names by replacing .c with .o
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft         # Build the libft library
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)
	@echo "pipex compiled successfully!"

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@make clean -C libft

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft

re: fclean all
