/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** header
*/

#ifndef H_RUNNER
#define H_RUNNER

#include <stdio.h>

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <math.h>
#include "my.h"

typedef struct window window_t;

#include "window.h"
#include "event_manager.h"
#include "map.h"
#include "game.h"
#include "object.h"
#include "parallax.h"

#define EXIT_ERROR 84

int run(char *path_map);

window_t *window_create(window_t *w, char *path_map);
void invert_fullscreen_state(window_t *w);

void event_manager_create(event_manager_t *evt_manager);
game_t *game_create(window_t *w, char *pathmap);
int create_elements(game_t *game);
int destroy_element(game_t *game);
object_t *object_create(const char *spritesheet_path, sfVector2f *pos,
sfVector2i *size, int nb_frame);
void parallax_create(window_t *w, int width, int height);

map_t *map_create(window_t *w, char *file_name);
map_t *map_reload(window_t *w);

#endif
