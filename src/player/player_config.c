/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** player object
*/

#include "my_runner.h"
#include "player.h"

extern const float PLAYER_POSX;
extern const int BLOCK_TEXTR_SIZE;
extern const int ID_EMPTY_BLOCK;
extern const int PLAYER_HEIGHT;

player_t *player_set_velocity(player_t *player, float x, float y)
{

    return player;
}

float player_get_posy(map_t *map, window_t *w)
{
    int block_x = ((float)PLAYER_POSX / map->block_size);
    float posy = -1;
    int leftrect_empty_block = ID_EMPTY_BLOCK * BLOCK_TEXTR_SIZE;

    for (int y = 0; y < map->height; y++) {
        if (map->map[block_x][y]->rect.left == leftrect_empty_block &&
        map->map[block_x][y + 1]->rect.left == leftrect_empty_block) {
            posy = w->height - ((1 + y) * map->block_size) - map->block_size;
            break;
        }
    }
    if (posy == -1 || (int)posy <= PLAYER_HEIGHT) {
        my_putstr_error("ERROR: no player position available in map file.\n");
        return -1;
    }
    return posy;
}
