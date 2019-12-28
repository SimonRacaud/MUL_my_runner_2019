/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** player object
*/

#include "my_runner.h"
#include "player.h"

extern const char *PATH_PLAY_SHEET;
extern const float PLAYER_POSX;
extern const int PLAYER_HEIGHT;
extern const sfVector2i PLAYER_SPRITE_SIZE;
extern const double PLAYER_FPMS;
extern const float PLAYER_JUMP_VELOCITY;
extern const float PLAYER_JUMP_GRAVITY;
extern const float PLAYER_MAX_VELOCITY;
extern const int P_NB_SPR;

static void player_destroy(player_t *player)
{
    DESTROY(player->obj);
}

static void player_move(player_t *player, map_t *map, window_t *w)
{
    if (player->velocity.y != 0) {
        player->obj->pos.y += player->velocity.y;
        if (player->velocity.y < PLAYER_MAX_VELOCITY)
            player->velocity.y += PLAYER_JUMP_GRAVITY;
    } else if (player->velocity.y < PLAYER_MAX_VELOCITY) {
        if (!player_check_hit_bottom(map, player, w))
            player->velocity.y += PLAYER_JUMP_GRAVITY;
        else
            player->obj->nb_frame = P_NB_SPR;
    }
    sfSprite_setPosition(player->obj->sprite, player->obj->pos);
}

static player_t *player_display(window_t *w)
{
    int ret;

    player_move(&w->game.player, &w->game.map, w);
    DISPLAY_OBJ(w->game.player.obj, w->window, w->game.clock);
    ret = player_check_collision(&w->game.player, &w->game.map, w);
    if (ret == EXIT_FAIL)
        w->evt.end_game(w, EXIT_FAIL);
    return (&w->game.player);
}

static void player_jump(player_t *player)
{
    if (player->velocity.y == 0) {
        player->velocity.y = PLAYER_JUMP_VELOCITY;
        player->obj->nb_frame = 0;
    }
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
    player->jump = &player_jump;
    player->set_velocity = &player_set_velocity;
    player->check_collision = &player_check_collision;
    player->obj = object_create(PATH_PLAY_SHEET, &pos, &sprite_size, P_NB_SPR);
    if (pos.y == -1 || !player->obj)
        return NULL;
    player->obj->rescale(player->obj, &size);
    player->obj->set_fps(player->obj, PLAYER_FPMS);
    player->velocity = (sfVector2f){0, 0};
    return player;
}
