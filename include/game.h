/*
** EPITECH PROJECT, 2019
** my_runner_2019
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
#include "object.h"
#include "window.h"

typedef struct game {
    void (*destroy)(struct game *game);
    struct game *(*display)(window_t *w);
    sfClock *clock;
    sfFont *font;
    map_t map;
    player_t player;
    object_t *duck;
    float speedx;
    double posx;
    int coin_counter;
    sfText *score;
    sfText *coins;
    char txt_score[13];
    char txt_coins[12];
} game_t;

int game_create_panel(game_t *game);
void game_destroy_panel(game_t *game);
void game_show_panel(window_t *w);
void game_update_panel(window_t *w);

#endif
