/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** player object
*/

#include "my_runner.h"
#include "player.h"

extern const char *PATH_PLAYER_SSHEET;
extern const float PLAYER_POSX;
extern const int PLAYER_HEIGHT;
extern const sfVector2i PLAYER_SPRITE_SIZE;
extern const double PLAYER_FPMS;

static void player_destroy(player_t *player)
{
    DESTROY(player->obj);
}

static void player_move(player_t *player)
{
    player->obj->pos.y += player->velocity.y;
    sfSprite_setPosition(player->obj->sprite, player->obj->pos);
}

static player_t *player_display(window_t *w)
{
    player_move(&w->game.player);
    DISPLAY_OBJ(w->game.player.obj, w->window, w->game.clock);
    return (&w->game.player);
}

static int player_check_collision(player_t *player, map_t *map, window_t *w)
{
    int ret;

    if (player->velocity.y > 0) {
        if (player_check_hit_bottom(map, player, w))
            player->velocity.y = 0;
    } else if (player->velocity.y < 0) {
        if (player_check_hit_top(map, player, w))
            player->velocity.y = -player->velocity.y;
    }
    ret = player_check_hit_front(map, player, w);
    if (ret == 1) {
        return EXIT_FAIL;
    } else if (ret == 2) {
        // COIN ADD
    }
    return EXIT_SUCCESS;
}

player_t *player_create(window_t *w)
{
    player_t *player = &w->game.player;
    sfVector2f pos;
    int block_size = w->game.map.block_size;
    sfVector2f size = {block_size, PLAYER_HEIGHT};
    sfVector2i sprite_size = PLAYER_SPRITE_SIZE;

    pos.x = (int)(PLAYER_POSX / block_size) * block_size;
    pos.y = player_get_posy(&w->game.map, w);
    player->destroy = &player_destroy;
    player->display = &player_display;
    player->set_velocity = &player_set_velocity;
    player->check_collision = &player_check_collision;
    player->obj = object_create(PATH_PLAYER_SSHEET, &pos, &sprite_size, 1);
    if (pos.y == -1 || !player->obj)
        return NULL;
    player->obj->rescale(player->obj, &size);
    player->obj->set_fps(player->obj, PLAYER_FPMS);
    player->velocity = (sfVector2f){0, 0};
    return player;
}
