##
## EPITECH PROJECT, 2019
## csfml_template_2019
## File description:
## Project makefile
##

SRC_DIR 	= ./src/
BUILD_DIR	= ./build
OBJ_DIR 	= ./obj

SRC	=	$(SRC_DIR)main.c				\
		$(SRC_DIR)constants.c			\
		$(SRC_DIR)run.c					\
		$(SRC_DIR)event_manager.c		\
		$(SRC_DIR)event_manager_more_events.c	\
		$(SRC_DIR)game.c				\
		$(SRC_DIR)game_create_destroy_elements.c \
		$(SRC_DIR)window.c				\
		$(SRC_DIR)object.c				\
		$(SRC_DIR)object_config.c		\
		$(SRC_DIR)object_management.c	\
		$(SRC_DIR)map.c					\
		$(SRC_DIR)map_display.c			\
		$(SRC_DIR)file_map.c			\
		$(SRC_DIR)file_map_check_map.c	\
		$(SRC_DIR)file_map_create_object_matrix.c \
		$(SRC_DIR)parallax.c			\
		$(SRC_DIR)parallax_update.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

CFLAGS	+= -Wall -Wextra -I./include

all:	$(NAME)

$(NAME):	LIB $(OBJ)
	gcc -o $(NAME) $(OBJ) -L./lib -lmy -l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio
	make clean

LIB:
	make -C ./lib/my

clean:
	rm -f  $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY :        clean fclean re
