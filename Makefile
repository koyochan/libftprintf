CC = cc
CFLAG = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = printf_d.c printf_p.c printf_s.c printf_u.c printf_x.c libftprintf.c ft_itoa.c
OBJS = $(SRCS:.c=.o)
%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@
all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re