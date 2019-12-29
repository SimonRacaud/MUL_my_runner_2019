/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** player manage collision
*/

#include "my_runner.h"
#include "player.h"

static void coin_add(map_t *map, player_t *player, window_t *w)
{
    sfVector2f coord;
    sfVector2i block_coord;

    w->game.coin_counter++;
    w->soundm.play(&w->soundm, SOUND_COIN);
    coord.y = player->obj->pos.y + player->obj->size.y - 5;
    coord.x = player->obj->pos.x + player->obj->size.x;
    while (map_get_typeblock(map, w, &coord) != BLOCK_COIN) {
        coord.y -= map->block_size;
        if (coord.y < player->obj->pos.y)
            break;
    }
    block_coord = map_get_block_coord(map, w, &coord);
    map->map[block_coord.x][block_coord.y] = map->type_block[3];
}

int player_check_collision(player_t *player, map_t *map, window_t *w)
{
    int ret;

    if (player->velocity.y > 0) {
        ret = player_check_hit_bottom(map, player, w);
        if (ret == 1) {
            player->velocity.y = 0;
        } else if (ret == -1)
            return EXIT_FAIL;
    } else if (player->velocity.y < 0) {
        ret = player_check_hit_top(map, player, w);
        if (ret == 1) {
            player->velocity.y = -player->velocity.y / 2;
        } else if (ret == -1)
            return EXIT_FAIL;
    }
    ret = player_check_hit_front(map, player, w);
    if (ret == 1) {
        return EXIT_FAIL;
    } else if (ret == 2) {
        coin_add(map, player, w);
    }
    return EXIT_SUCCESS;
}
