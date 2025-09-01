# Compiler and flags
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g -I$(INC_DIR)
AR		= ar
ARFLAGS	= rcs

# Directories
OBJ_DIR	= objs
SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

# Target
NAME = $(BIN_DIR)/main.out

# Source files
SRC = main.c ft_lst_ops.c ft_lst_base.c ft_utils1.c

# Objects
OBJ	= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Default target: build library without bonus
all: $(NAME)

# Build objects
$(NAME): $(OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# Create directories if not present
$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

# Compile library objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -rf $(OBJ_DIR)

# Clean object and executable files
fclean: clean
	rm -rf $(BIN_DIR)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re