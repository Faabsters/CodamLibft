SRCS	= ft_atoi.c \
		  ft_bzero.c \
		  ft_calloc.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_itoa.c \
		  ft_memmove.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memchr.c \
		  ft_memset.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_substr.c \
		  ft_split.c \
		  ft_strtrim.c \
		  ft_strjoin.c \
		  ft_strmapi.c \
		  ft_strchr.c \
		  ft_strdup.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_strlen.c \
		  ft_strrchr.c \
		  ft_strnstr.c \
		  ft_strncmp.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  ft_striteri.c

OBJS	= ${SRCS:.c=.o}

BONUS = ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
			
BONUS_OBJS = $(BONUS:.c=.o)

NAME	= libft.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

AR 		= ar -rsc

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -c $(SRCS)
			$(AR) $(NAME) $(OBJS) libft.h

all:		$(NAME)

clean:		
			$(RM) $(OBJS) $(BONUS_OBJS)


fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:		$(BONUS_OBJS)
			$(AR) $(NAME) $(BONUS_OBJS) libft.h

.PHONY:		all clean fclean re bonus
