/*
** EPITECH PROJECT, 2019
** csfml_2019
** File description:
** header
*/

#ifndef H_RUNNER
#define H_RUNNER

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <math.h>
#include "my.h"
#include "event_manager.h"
#include "window.h"
#include "map.h"
#include "game.h"
#include "object.h"
#include "parallax.h"

static const int CHAR_SIZE = 0;
static const int W_WIDTH = 1920;
static const int W_HEIGHT = 1080;
static const int W_BPP = 32;
static const int FRAMERATE = 60;
static const int PARALLAX_SPEED = 3;
static const char *PATH_FONT = "";
static const char *TITLE_WINDOW = "My Runner";

static const char *PATH_DUCK = "duck_spritesheet.png";

void event_manager_create(event_manager_t *evt_manager);

game_t *game_create(game_t *game, char *pathmap, char *pathfont);

window_t *window_create(void);

object_t *object_create(char *spritesheet_path, sfVector2f *pos,
sfVector2i *size, int nb_frame);

void parallax_create(parallax_t *parallax, int width, int height);

#endif
