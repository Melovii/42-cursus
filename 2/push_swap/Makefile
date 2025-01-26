NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address
# CFLAGS = -Wall -Werror -Wextra
RM = rm -fr

# Source files
SRC_DIR = src
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/index.c \
       $(SRC_DIR)/op_p.c \
       $(SRC_DIR)/op_r.c \
       $(SRC_DIR)/op_rr.c \
       $(SRC_DIR)/op_s.c \
       $(SRC_DIR)/quick_sort.c \
       $(SRC_DIR)/sort_handler.c \
       $(SRC_DIR)/sort_utils.c

# Utils files
UTILS_DIR = utils
UTILS = $(UTILS_DIR)/ft_atoi.c \
        $(UTILS_DIR)/ft_isdigit.c \
        $(UTILS_DIR)/ft_lstadd_back_bonus.c \
        $(UTILS_DIR)/ft_lstlast_bonus.c \
        $(UTILS_DIR)/ft_lstnew_bonus.c \
        $(UTILS_DIR)/ft_lstsize_bonus.c \
        $(UTILS_DIR)/ft_putstr_fd.c \
        $(UTILS_DIR)/ft_split.c \
        $(UTILS_DIR)/ft_calloc.c \
        $(UTILS_DIR)/ft_strlen.c \
        $(UTILS_DIR)/ft_putchar_fd.c \
        $(UTILS_DIR)/ft_bzero.c

# Object files
OBJS = $(SRCS:.c=.o) $(UTILS:.c=.o)

# Bonus files (if needed)
SRCS_BONUS = src/checker_bonus.c # Add other bonus files if necessary
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o checker

.PHONY: all clean fclean re bonus