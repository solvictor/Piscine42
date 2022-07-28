SRCDIR	= srcs/
SRC		= $(SRCDIR)main.c $(SRCDIR)ft.c $(SRCDIR)input.c $(SRCDIR)map.c \
			$(SRCDIR)ft2.c $(SRCDIR)ft_split.c $(SRCDIR)bsq_solver.c
OBJ		= $(SRC:.c=.o)
NAME	= bsq
CC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror
HEADERS	= includes/

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEADERS)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:            fclean all
