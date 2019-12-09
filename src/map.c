/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** map object
*/

#include "my_runner.h"
#include "map.h"

static void map_destroy(map_t *map)
{
    map->parallax.destroy(map->parallax);
    for (int i = 0; i < map->nb_type_block; i++) {
        map->type_block[i].destroy(map->type_block[i]);
    }
    free(map->type_block);
    for (int i = 0; i < map->width; i++)
        free(map->map[i]);
    free(map->buffer);
}

static map_t *map_display(map_t *w)
{

}

map_t *map_create(map_t *map)
{
    map->destroy = map_destroy;
    map->display = map_display;
}
