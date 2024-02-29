SRC		= ft_printf.c ft_printf_utils.c ft_printf_specifiers.c

OBJ		= $(SRC:.c=.o)

NAME		= libftprintf.a

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

LIBFT_DIR	= ./libft

LIBFT		= $(LIBFT_DIR)/libft.a

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) all

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re