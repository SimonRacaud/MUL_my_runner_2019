/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** player hitbox
*/

#include "my_runner.h"
#include "player.h"

extern const int CODE_HIT_BLOCK;
extern const int CODE_NO_HIT_BLOCK;
extern const int CODE_COIN_BLOCK;
extern const int CODE_TRAP;
extern const int CODE_MALUS_BLOCK;

int get_hitcode(map_t *map, window_t *w, sfVector2f *point)
{
    object_type_e ret;

    if (point->y >= w->height) {
        return CODE_TRAP;
    }
    ret = map->get_typeblock(map, w, point);
    if (ret == BLOCK_MALUS) {
        return CODE_MALUS_BLOCK;
    }
    if (ret == BLOCK_EMPTY || ret == BLOCK_EMPTY_TXR) {
        return CODE_NO_HIT_BLOCK;
    } else if (ret == BLOCK_COIN) {
        return CODE_COIN_BLOCK;
    } else {
        if (ret == BLOCK_TRAP || ret == ENEMY)
            return CODE_TRAP;
        else
            return CODE_HIT_BLOCK;
    }
}

int player_check_hit_top(map_t *map, player_t *player, window_t *w)
{
    sfVector2f point;
    int ret;

    point.y = player->obj->pos.y - 8;
    point.x = player->obj->pos.x;
    ret = get_hitcode(map, w, &point);
    if (ret == CODE_HIT_BLOCK)
        return 1;
    else if (ret == CODE_TRAP)
        return -1;
    point.x +=  player->obj->size.x;
    ret = get_hitcode(map, w, &point);
    if (ret == CODE_HIT_BLOCK)
        return 1;
    else if (ret == CODE_TRAP)
        return -1;
    return 0;
}

int player_check_hit_bottom(map_t *map, player_t *player, window_t *w)
{
    sfVector2f point;
    int ret;

    point.y = player->obj->pos.y + player->obj->size.y + player->velocity.y;
    point.x = player->obj->pos.x;
    ret = get_hitcode(map, w, &point);
    if (ret == CODE_HIT_BLOCK)
        return 1;
    else if (ret == CODE_TRAP) {
        return -1;
    }
    point.x +=  player->obj->size.x;
    ret = get_hitcode(map, w, &point);
    if (ret == CODE_HIT_BLOCK)
        return 1;
    else if (ret == CODE_TRAP)
        return -1;
    return 0;
}

int player_check_hit_front(map_t *map, player_t *player, window_t *w)
{
    sfVector2f point;
    int ret;

    point.x = player->obj->pos.x + player->obj->size.x - 10;
    point.y = player->obj->pos.y + 10;
    for (int i = 0; i < 3; i++) {
        ret = get_hitcode(map, w, &point);
        if (ret == CODE_HIT_BLOCK || ret == CODE_TRAP) {
            return 1;
        } else if (ret == CODE_COIN_BLOCK) {
            return 2;
        }
        if (ret == CODE_MALUS_BLOCK) {
            return 3;
        }
        point.y += map->block_size - 10;
    }
    return 0;
}
