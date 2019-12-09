/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** game object
*/

#include "my_runner.h"
#include "game.h"

static void game_destroy(game_t *game)
{
    //sfFont_destroy(w->font);
    //destroy_object(w->duck);
}

static game_t *game_display(game_t *game)
{

    return game;
}

game_t *game_create(game_t *game, char *pathmap, char *pathfont)
{
    game->destroy = &game_destroy;
    game->display = &game_display;
    game->clock = sfClock_create();
    //w->font = sfFont_createFromFile(PATH_FONT);

    if (!game->font) {
        return NULL;
    }
    return game;
}
