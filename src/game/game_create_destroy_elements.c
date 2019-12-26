/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** game : create/destroy objects of the game
*/

#include "my_runner.h"
#include "game.h"

extern const char *PATH_DUCKSHEET;

int create_elements(game_t *game)
{
    game->duck = object_create(PATH_DUCKSHEET, &(sfVector2f){10, 10},
    &(sfVector2i){110, 110}, 3);
    if (game->duck == NULL)
        return EXIT_ERROR;
    game->duck->set_speed(game->duck, 10, 10);
    game->duck->set_fps(game->duck, 100);
    return EXIT_SUCCESS;
}

int destroy_element(game_t *game)
{
    game->duck->destroy(game->duck);
    //destroy player
    return EXIT_SUCCESS;
}
