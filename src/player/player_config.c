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
extern const int PLAYER_HEIGHT;

player_t *player_set_velocity(player_t *player, float x, float y)
{
    player->velocity.x = x;
    player->velocity.y = y;
    return player;
}

float player_get_posy(map_t *map, window_t *w)
{
    int block_x = ((float)PLAYER_POSX / map->block_size);
    float posy = -1;

    for (int y = 0; y < map->height; y++) {
        if (map->map[block_x][y]->type == BLOCK_EMPTY &&
        map->map[block_x][y + 1]->type == BLOCK_EMPTY) {
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
