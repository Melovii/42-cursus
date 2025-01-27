NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -fr

SRC_DIR = src
UTILS_DIR = utils

SRCS =	$(SRC_DIR)/main.c 			\
		$(SRC_DIR)/index.c 			\
		$(SRC_DIR)/op_p.c 			\
		$(SRC_DIR)/op_r.c 			\
		$(SRC_DIR)/op_rr.c 			\
		$(SRC_DIR)/op_s.c 			\
		$(SRC_DIR)/quick_sort.c 	\
		$(SRC_DIR)/sort_handler.c 	\
		$(SRC_DIR)/sort_utils.c

UTILS =	$(UTILS_DIR)/ft_atoi.c 				\
		$(UTILS_DIR)/ft_bzero.c 			\
		$(UTILS_DIR)/ft_calloc.c 			\
		$(UTILS_DIR)/ft_isdigit.c 			\
		$(UTILS_DIR)/ft_lstadd_back_bonus.c \
		$(UTILS_DIR)/ft_lstlast_bonus.c 	\
		$(UTILS_DIR)/ft_lstnew_bonus.c 		\
		$(UTILS_DIR)/ft_lstsize_bonus.c 	\
		$(UTILS_DIR)/ft_putchar_fd.c 		\
		$(UTILS_DIR)/ft_putstr_fd.c 		\
		$(UTILS_DIR)/ft_split.c 			\
		$(UTILS_DIR)/ft_strlen.c

OBJS = $(SRCS:.c=.o) $(UTILS:.c=.o)

INCLUDES = -I$(SRC_DIR) -I$(UTILS_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# ! remove tests before evaluation

test2:		$(NAME)	
				$(eval ARG = $(shell shuf -i 0-100 -n 2))
				./push_swap $(ARG) | ./checker $(ARG)
				@echo -n "Instructions: "
				@./push_swap $(ARG) | wc -l

test3:		$(NAME)	
				$(eval ARG = $(shell shuf -i 0-100 -n 3))
				./push_swap $(ARG) | ./checker $(ARG)
				@echo -n "Instructions: "
				@./push_swap $(ARG) | wc -l

test5:		$(NAME)	
				$(eval ARG = $(shell shuf -i 0-5000 -n 5))
				./push_swap $(ARG) | ./checker $(ARG)
				@echo -n "Instructions: "
				@./push_swap $(ARG) | wc -l

test100:	$(NAME)	
				$(eval ARG = $(shell shuf -i 0-5000 -n 100))
				./push_swap $(ARG) | ./checker $(ARG)
				@echo -n "Instructions: "
				@./push_swap $(ARG) | wc -l

test500:	$(NAME)	
				$(eval ARG = $(shell shuf -i 0-5000 -n 500))
				./push_swap $(ARG) | ./checker $(ARG)
				@echo -n "Instructions: "
				@./push_swap $(ARG) | wc -l

valgrind:	$(NAME)	
				$(eval ARG = $(shell shuf -i 0-5000 -n 100))
				valgrind ./push_swap $(ARG)

# ! update PHONY once tests are removed

.PHONY: all clean fclean re run valgrind test2 test3 test5 test100 test500 
