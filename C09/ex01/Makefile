NAME = libft.a
SRCDIR = srcs/
INCLUDESDIR = includes/
CC = gcc
SRCS = $(SRCDIR)ft_putchar.c $(SRCDIR)ft_swap.c $(SRCDIR)ft_putstr.c \
		$(SRCDIR)ft_strlen.c $(SRCDIR)ft_strcmp.c
OBJS = $(SRCS:.c=.o)

.c.o: 
	$(CC) -Wall -Wextra -Werror -c $< -o $(<:.c=.o) -I $(INCLUDESDIR)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
