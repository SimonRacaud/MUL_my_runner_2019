/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** player manage coin add
*/

#include "my_runner.h"
#include "player.h"

static sfVector2i coin_find_in_column(map_t *map, player_t *player,
window_t *w, float coordx)
{
    sfVector2f coord;

    coord.y = player->obj->pos.y + player->obj->size.y + map->block_size;
    coord.x = coordx;
    while (map_get_typeblock(map, w, &coord) < BLOCK_COIN) {
        if (coord.y < player->obj->pos.y)
            break;
        coord.y -= map->block_size;
    }
    if (map_get_typeblock(map, w, &coord) >= BLOCK_COIN)
        return map_get_block_coord(map, w, &coord);
    return (sfVector2i){-1, -1};
}

static void coin_manage_coin(window_t *w, sfBool is_malus)
{
    if (!is_malus) {
        w->game.coin_counter++;
        w->game.bonus_score += 10;
        w->soundm.play(&w->soundm, SOUND_COIN);
    } else {
        if (w->game.coin_counter > 0) {
            w->game.coin_counter--;
        }
        if (w->game.bonus_score >= 10) {
            w->game.bonus_score -= 10;
        }
        w->soundm.play(&w->soundm, SOUND_DIE);
    }
}

void coin_add(map_t *map, player_t *player, window_t *w, sfBool is_malus)
{
    float coordx = player->obj->pos.x + player->obj->size.x;
    sfVector2i block_coord = coin_find_in_column(map, player, w, coordx);
    float stop_coord = player->obj->pos.x - (2 * player->obj->size.x);

    while (block_coord.x == -1 && coordx > stop_coord) {
        block_coord = coin_find_in_column(map, player, w, coordx);
        coordx -= map->block_size;
    }
    coin_manage_coin(w, is_malus);
    if (block_coord.x != -1)
        map->map[block_coord.x][block_coord.y] = map->type_block[3];
}
