##
## EPITECH PROJECT, 2024
## Compile mylib
## File description:
## Makefile that compiles the lib
##

NAME		=	open

SRCDIR		=	src/

SRCS		=	$(shell find $(SRCDIR) -type f -name "*.c")

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-Wall -Wextra
CPPFLAGS	=	-Iinclude
CSFML		=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(CSFML)

clean:
	rm -f $(OBJS)
	rm -f *~

fclean:	clean
	rm -f $(NAME_TEST)
	rm -f $(NAME)

re:	fclean all
