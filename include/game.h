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

#define GET_TIME_CLOCK(clock) sfClock_getElapsedTime(clock)
#define GET_MSECOND_CLOCK(clock) sfTime_asMilliseconds(GET_TIME_CLOCK(clock))
#define GET_SECOND_CLOCK(clock) sfTime_asSeconds(GET_TIME_CLOCK(clock))

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
    float sub_time;
    sfClock *clock_score;
    int coin_counter;
    sfBool infinite_mode;
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
