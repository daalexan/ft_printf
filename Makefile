NAME = libftprintf.a

HEADER = ./include/libft/
PRINT_HEADER = ./include/

SRC = src

CFLAGS = -Wall -Werror -Wextra

CC = gcc

LIB_FILES = ./include/libft/
PRINTF_FILES =  src/ft_printf.c \
				src/ft_parses.c \
				src/functions/ft_bin_handle.c \
				src/functions/ft_char_handle.c \
				src/functions/ft_chrwrite_handle.c \
				src/functions/ft_escape_handle.c \
				src/functions/ft_hex_handle.c \
				src/functions/ft_init_handler.c \
				src/functions/ft_int_handle.c \
				src/functions/ft_long_handle.c \
				src/functions/ft_null_handle.c \
				src/functions/ft_octal_handle.c \
				src/functions/ft_ptr_handle.c \
				src/functions/ft_str_handle.c \
				src/functions/ft_uint_handle.c \
				src/functions/ft_unsigned_handle.c \
				src/functions/ft_wchar_handle.c \
				src/functions/ft_wstr_handle.c \
				src/addfunc/ft_nbrlen.c \
				src/addfunc/ft_nbrstrlen.c \
				src/addfunc/ft_nforcepref.c \
				src/addfunc/ft_print_space.c \
				src/addfunc/ft_unsg.c

OBJ = $(PRINTF_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB_FILES)libft.a
	ar rc $(NAME) $(OBJ) $(LIB_FILES)*.o
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER) -I $(PRINT_HEADER)

$(LIB_FILES)libft.a:
	make -C $(LIB_FILES)
clean:
	make clean -C $(LIB_FILES)
	rm -f $(OBJ)
fclean: clean
	make fclean -C $(LIB_FILES)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re