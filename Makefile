# Compiler and flags
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g -I$(INC_DIR)
AR		= ar
ARFLAGS	= rcs

# Directories
OBJ_DIR	= objs
SRC_DIR = src
INC_DIR = include
FT_PRINTF_DIR = ft_printf

# Target
NAME = push_swap

# Source files
SRC = main.c parse_utils1.c parse_utils2.c push.c rotate.c \
	reverse_rotate.c swap.c \
	free_utils.c norm_and_index.c radix_sort.c is_sorted.c \
	choose_sort.c three_to_five_sort.c

# Header files
HEADER_NAMES = choose_sort.h is_sorted.h norm_and_index.h push.h rotate.h \
	free_utils.h libft.h parse_utils1.h radix_sort.h swap.h \
	ft_printf.h main.h parse_utils2.h reverse_rotate.h \
	three_to_five_sort.h
HEADERS = $(patsubst %,$(INC_DIR)/%,$(HEADER_NAMES))

# Objects
OBJ	= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Default target: build library without bonus
all: makeprintf $(NAME)

# Build objects
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@  ft_printf/libftprintf.a

makeprintf:
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(OBJ_DIR):
	mkdir -p $@

# Compile library objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)| $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

# Clean object and executable files
fclean: clean
	rm -rf $(BIN_DIR)
	rm $(FT_PRINTF_DIR)/libftprintf.a

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
