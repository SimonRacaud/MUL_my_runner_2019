##
## EPITECH PROJECT, 2019
## csfml_template_2019
## File description:
## Project makefile
##

BUILD_DIR	= ./build
SRC_DIR 	= ./src
OBJ_DIR 	= ./obj

SRC	=	main.c				\
		event_manager.c		\
		object.c			\
		create_window.c		\
		display_window.c	\
		parallax.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

CFLAGS	+= -Wall -Wextra -I./include

all:	$(NAME)

$(NAME):	LIB $(OBJ)
	gcc -o $(NAME) $(OBJ) -L./lib -lmy -l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio

LIB:
	make -C ./lib/my

clean:
	rm -f  $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY :        clean fclean re
