/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** MAP : Get the type of the map block on specific coordinates.
*/

#include "my_runner.h"

extern const char MAP_BLOCK_CHAR[];
extern const int BLOCK_TEXTR_SIZE;
extern const int NB_TYPE_BLOCK;

sfVector2i map_get_block_coord(map_t *map, window_t *w, sfVector2f *coord)
{
    sfVector2i block_coord;
    int start_disp_cols = (w->game.posx / map->block_size);
    double cols_posx = ((start_disp_cols * map->block_size) - w->game.posx);

    block_coord.x = start_disp_cols;
    block_coord.x += (float)(coord->x + (-cols_posx)) / map->block_size;
    block_coord.y = (float)(w->height - coord->y) / map->block_size;
    return block_coord;
}

object_type_e map_get_typeblock(map_t *map, window_t *w, sfVector2f *coord)
{
    sfVector2i block_coord;
    object_t *block;

    block_coord = map_get_block_coord(map, w, coord);
    block = map->map[block_coord.x][block_coord.y];
    return block->type;
}
