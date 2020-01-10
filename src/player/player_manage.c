/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** manage player object
*/

#include "my_runner.h"
#include "player.h"

extern const float PLAYER_JUMP_VELOCITY;
extern const float PLAYER_JUMP_GRAVITY;
extern const float PLAYER_MAX_VELOCITY;
extern const int P_NB_SPR;

int player_move(player_t *player, map_t *map, window_t *w)
{
    int ret;

    if (player->velocity.y != 0) {
        player->obj->pos.y += player->velocity.y;
        if (player->velocity.y < PLAYER_MAX_VELOCITY)
            player->velocity.y += PLAYER_JUMP_GRAVITY;
    } else if (player->velocity.y == 0) {
        ret = player_check_hit_bottom(map, player, w);
        if (ret == 0)
            player->velocity.y = (-PLAYER_JUMP_VELOCITY / 2);
        else if (ret == -1) {
            return EXIT_FAIL;
        }
        if (player->obj->nb_frame == 0)
            player->obj->nb_frame = P_NB_SPR;
    }
    sfSprite_setPosition(player->obj->sprite, player->obj->pos);
    return EXIT_SUCCESS;
}

void player_jump(window_t *w)
{
    player_t *player = &w->game.player;

    if (player->velocity.y == 0) {
        player->velocity.y = PLAYER_JUMP_VELOCITY;
        player->obj->nb_frame = 0;
        player->obj->set_frame(player->obj, P_NB_SPR);
        w->soundm.play(&w->soundm, SOUND_JUMP);
    }
}
