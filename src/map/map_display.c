/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** display the right part of the map on the screen
*/

#include "my_runner.h"

static void show_row(window_t *w, int row, int max_row, sfVector2f *pos)
{
    map_t *map = &w->game.map;

    for (int y = 0; y < max_row; y++) {
        map->map[row][y]->pos = *pos;
        sfSprite_setPosition(map->map[row][y]->sprite, map->map[row][y]->pos);
        pos->y -= map->block_size;
        if (map->map[row][y]->type != BLOCK_EMPTY) {
            DISPLAY_OBJ(map->map[row][y], w->window, w->game.clock);
        }
    }
}

int map_show_map(window_t *w)
{
    int start_cols = (w->game.posx / w->game.map.block_size);
    sfVector2f pos = {0, w->height - w->game.map.block_size};

    pos.x = ((start_cols * w->game.map.block_size) - w->game.posx);
    for (int x = start_cols; x < start_cols + w->game.map.nb_disp_cols; x++) {
        if (x >= w->game.map.width)
            break;
        show_row(w, x, w->game.map.nb_disp_rows, &pos);
        pos.x += w->game.map.block_size;
        pos.y = (w->height - w->game.map.block_size);
    }
    return EXIT_SUCCESS;
}
