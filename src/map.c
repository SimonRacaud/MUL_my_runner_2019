/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** map object
*/

#include "my_runner.h"
#include "map.h"

extern const int BLOCK_SIZE;
extern const int NB_TYPE_BLOCK;
extern const char *PATH_BLOCK01;

static void map_destroy(map_t *map)
{
    map->parallax.destroy(&map->parallax);
    /*for (int i = 0; i < map->nb_type_block; i++) {
        map->type_block[i]->destroy(map->type_block[i]);
    }
    free(map->type_block);
    for (int i = 0; i < map->width; i++)
        free(map->map[i]);
    free(map->buffer);*/
}

static map_t *map_display(window_t *w)
{
    w->game.map.parallax.move(&w->game.map.parallax, w->game.clock);
    w->game.map.parallax.display(&w->game.map.parallax, w->window);
    return (&w->game.map);
}

map_t *map_create(window_t *w)
{
    w->game.map.destroy = map_destroy;
    w->game.map.display = map_display;
    w->game.map.block_size = BLOCK_SIZE;
    parallax_create(w, w->width, w->height);
    return (&w->game.map);
}
