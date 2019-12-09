/*
** EPITECH PROJECT, 2019
** csfml_2019
** File description:
** header
*/

#ifndef H_GAME
#define H_GAME

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>

#include "map.h"
#include "player.h"

typedef struct game {
    void (*destroy)(game_t *game);
    game_t *(*display)(game_t *game);
    sfClock *clock;
    sfFont *font;
    map_t map;
    player_t player;
    object_t *duck;
} game_t;

#endif
