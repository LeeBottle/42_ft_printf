NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	ft_printf_func.c\
	ft_printf_func2.c\
	ft_printf_utils.c
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME) $(EXEC)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
	ar rcs $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	rm -rf $(OBJS) $(EXEC_OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	rm -rf $(NAME) $(EXEC)

re: fclean all

.PHONY: all clean fclean re
