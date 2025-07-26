# Program name
NAME		=	megaphone

# Flags and settings
STD			=	c++98
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

INCLUDES	=	-Iincludes

SRCS_DIR	=	srcs
OBJS_DIR	=	objs

SRC_FILES	=	megaphone.cpp		\

OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

SRCS		=	$(addprefix $(SRCS_DIR)/,$(SRC_FILES))
OBJS		=	$(addprefix $(OBJS_DIR)/,$(OBJ_FILES))

# Colors
GREEN		=	\033[0;32m
BLUE		=	\033[1;34m
YELLOW		=	\033[1;33m
RESET		=	\033[0m

# Targets
all: $(NAME)

# Compile source files into object files
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling: $<$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Create the objects directory if it doesn't exist
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Link object files to create the final binary
$(NAME): $(OBJS)
	@echo "$(BLUE)Linking: $(NAME)$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Build complete ✔$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -fr $(OBJS_DIR)

fclean: clean
	@echo "$(YELLOW)Removing binary...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
