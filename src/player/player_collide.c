/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** player manage collision
*/

#include "my_runner.h"
#include "player.h"

static void set_player_on_block(player_t *player, map_t *map)
{
    player->obj->pos.y = ceil(player->obj->pos.y / map->block_size);
    player->obj->pos.y *= map->block_size;
}

static int player_manage_hit_font(player_t *player, map_t *map, window_t *w)
{
    int ret = player_check_hit_front(map, player, w);
    if (ret == 1) {
        return EXIT_FAIL;
    } else if (ret == 2) {
        coin_add(map, player, w);
    }
    return EXIT_SUCCESS;
}

int player_check_collision(player_t *player, map_t *map, window_t *w)
{
    int ret;

    if (player->velocity.y > 0) {
        ret = player_check_hit_bottom(map, player, w);
        if (ret == 1) {
            player->velocity.y = 0;
            set_player_on_block(player, map);
        } else if (ret == -1)
            return EXIT_FAIL;
    } else if (player->velocity.y < 0) {
        ret = player_check_hit_top(map, player, w);
        if (ret == 1) {
            player->velocity.y = -player->velocity.y / 2;
        } else if (ret == -1)
            return EXIT_FAIL;
    }
    return player_manage_hit_font(player, map, w);
}
