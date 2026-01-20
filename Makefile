CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCE_FILES = 	dictionary.c ft_bzero.c ft_calloc.c ft_memset.c \
				ft_printf.c ft_strlen.c handle_char.c handle_int.c \
				handle_lowerhex.c handle_percent.c handle_ptr.c \
				handle_str.c handle_upperhex.c print_hex.c
OBJECT_FILES = $(SOURCE_FILES:%.c=%.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	ar rcs $(NAME) $(OBJECT_FILES)

clean:
	rm -f $(OBJECT_FILES)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re