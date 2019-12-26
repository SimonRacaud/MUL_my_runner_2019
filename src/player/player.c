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

static player_t *player_display(window_t *w)
{
    DISPLAY_OBJ(w->game.player.obj, w->window, w->game.clock);
}

static int player_check_collision(player_t *player, map_t *map)
{

}

player_t *player_create(window_t *w)
{
    player_t *player = &w->game.player;
    sfVector2f pos;
    int block_size = w->game.map.block_size;
    sfVector2f size = {block_size, PLAYER_HEIGHT};

    pos.x = (int)(PLAYER_POSX / block_size) * block_size;
    pos.y = player_get_posy(&w->game.map, w);
    player->destroy = &player_destroy;
    player->display = &player_display;
    player->set_velocity = &player_set_velocity;
    player->check_collision = &player_check_collision;
    player->obj = object_create(PATH_PLAYER_SSHEET, &pos, &PLAYER_SPRITE_SIZE, 1);
    if (pos.y == -1 || !player->obj)
        return NULL;
    player->obj->rescale(player->obj, &size);
    player->obj->set_fps(player->obj, PLAYER_FPMS);
    return player;
}
