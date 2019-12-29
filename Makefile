##
## EPITECH PROJECT, 2019
## csfml_template_2019
## File description:
## Project makefile
##

SRC_DIR 	= ./src/
BUILD_DIR	= ./build
OBJ_DIR 	= ./obj

SRC	=	$(SRC_DIR)main.c						\
		$(SRC_DIR)constants.c					\
		$(SRC_DIR)run.c							\
		$(SRC_DIR)event/event_manager.c					\
		$(SRC_DIR)event/event_manager_more_events.c		\
		$(SRC_DIR)game/game.c							\
		$(SRC_DIR)game/game_panel.c							\
		$(SRC_DIR)game/game_create_destroy_elements.c 	\
		$(SRC_DIR)window/window.c				\
		$(SRC_DIR)object/object.c				\
		$(SRC_DIR)object/object_config.c		\
		$(SRC_DIR)object/object_management.c	\
		$(SRC_DIR)map/map.c						\
		$(SRC_DIR)map/map_display.c				\
		$(SRC_DIR)map/map_get_typeblock_coord.c	\
		$(SRC_DIR)map/file_map.c				\
		$(SRC_DIR)map/file_map_check_map.c		\
		$(SRC_DIR)map/file_map_create_object_matrix.c 	\
		$(SRC_DIR)map/file_map_load_standard_block.c 	\
		$(SRC_DIR)player/player.c				\
		$(SRC_DIR)player/player_hitbox.c		\
		$(SRC_DIR)player/player_config.c		\
		$(SRC_DIR)player/player_collide.c		\
		$(SRC_DIR)parallax/parallax.c			\
		$(SRC_DIR)parallax/parallax_update.c	\
		$(SRC_DIR)sound/sound_manager.c			\

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
