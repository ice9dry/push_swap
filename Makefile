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
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf

# Target
NAME = $(BIN_DIR)/main.out

# Source files
SRC = main.c utils1.c

# Objects
OBJ	= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Default target: build library without bonus
all: makelibft makeprintf $(NAME)

# Build objects
$(NAME): $(OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@  libft/libft.a ft_printf/libftprintf.a

makelibft:
	@$(MAKE) -C $(LIBFT_DIR) bonus

makeprintf:
	@$(MAKE) -C $(FT_PRINTF_DIR)

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
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean

# Clean object and executable files
fclean: clean
	rm -rf $(BIN_DIR)
	rm $(FT_PRINTF_DIR)/libftprintf.a
	rm $(LIBFT_DIR)/libft.a

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
