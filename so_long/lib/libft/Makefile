# COMPILER
GCC = cc
# FLAGS FOR COMPILATION
FLAGS = -Wall -Wextra -Werror
# LIBRARY NAME
NAME = libft.a
# LIST OF SOURCE FILES
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
    ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
    ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c \
    ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c \
    ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c get_next_line.c
# OBJECT FILES
OBJS = $(SRCS:.c=.o)
# ALL RULE
# RULES TO MAKE A LIBRARY
all: $(NAME)

%.o: %.c
	$(GCC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# RULES FOR CREATING OBJECT FILES
clean:
	rm -f $(OBJS)
# RULES TO CLEAN EVERYTHING
fclean: clean
	rm -f $(NAME)
# RULES FOR RECOMPILATION
re: fclean all

.PHONY: all clean fclean re
