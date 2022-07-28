SRCDIR	= srcs/
SRC		= $(SRCDIR)main.c
OBJ		= $(SRC:.c=.o)
NAME	= do-op
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
