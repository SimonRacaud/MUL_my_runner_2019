/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** player manage collision
*/

#include "my_runner.h"
#include "player.h"

static sfVector2i coin_find(map_t *map, player_t *player,
window_t *w)
{
    sfVector2i block_coord = {0, 0};
    sfVector2f coorda;
    sfVector2f coordb;

    coorda.y = player->obj->pos.y + player->obj->size.y - 5;
    coorda.x = player->obj->pos.x + player->obj->size.x;
    coordb.y = player->obj->pos.y + player->obj->size.y - 5;
    coordb.x = player->obj->pos.x;
    while (1) {
        if (map_get_typeblock(map, w, &coorda) == BLOCK_COIN ||
        map_get_typeblock(map, w, &coordb) == BLOCK_COIN) {
            block_coord = map_get_block_coord(map, w, &coorda);
            break;
        }
        coorda.y -= map->block_size;
        coordb.y -= map->block_size;
        if (coorda.y < player->obj->pos.y || coordb.y < player->obj->pos.y)
            break;
    }
    return block_coord;
}

static void coin_add(map_t *map, player_t *player, window_t *w)
{
    sfVector2i block_coord = coin_find(map, player, w);

    w->game.coin_counter++;
    w->soundm.play(&w->soundm, SOUND_COIN);
    if (!(block_coord.x == 0 && block_coord.y == 0))
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
