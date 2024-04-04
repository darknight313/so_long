# Compiler and flags
CC = cc
# CFLAGS = -Wall -Wextra -Werror

# Name of the library
NAME = libftprintf.a

# Archive program and files
AR = ar
ARFLAGS = rc

# Source files and objects
SRCS = ft_printf.c ft_execute.c ft_put_address.c

OBJS = $(SRCS:.c=.o)

# ANSI color codes
GREEN = \033[0;32m
RED = \033[0;30m
NC = \033[0m

# Target: Build the library and, optionally, the executable
all: $(NAME)
	@echo "$(GREEN)Build successful$(NC)"

%.o: %.c
	@echo "$(GREEN)Compiling $<$(NC)"
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(GREEN)Archiving object files$(NC)"
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

# Clean up
clean:
	@echo "$(RED)Cleaning up$(NC)"
	rm -f $(OBJS)
# Force clean, including the library and executable
fclean: clean
	@echo "$(RED)Force cleaning$(NC)"
	rm -f $(NAME)
# Rebuild
re: fclean all
	@echo "$(GREEN)Rebuild complete$(NC)"

.PHONY: all clean fclean re
