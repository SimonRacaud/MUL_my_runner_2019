/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** player object
*/

#include "my_runner.h"
#include "player.h"

extern const float PLAYER_POSX;
extern const int PLAYER_HEIGHT;
extern const sfVector2i PLAYER_SPRITE_SIZE;
extern const double PLAYER_FPMS;
extern const float PLAYER_JUMP_VELOCITY;
extern const float PLAYER_JUMP_GRAVITY;
extern const int P_NB_SPR;
extern const char *PATH_PLAY_SHEET[];
extern const int NB_PLAYER_SHEET;
extern const char *PLAYER_OPTION_SPRITE[];

static void player_destroy(player_t *player)
{
    DESTROY(player->obj);
}

static player_t *player_display(window_t *w)
{
    int player_pos_in_map = w->game.player.obj->pos.x + w->game.posx;
    int player_block_pos = player_pos_in_map / w->game.map.block_size;
    int ret;

    ret = player_move(&w->game.player, &w->game.map, w);
    if (ret == EXIT_FAIL)
        w->evt.end_game(w, EXIT_FAIL);
    DISPLAY_OBJ(w->game.player.obj, w->window, w->game.clock);
    ret = player_check_collision(&w->game.player, &w->game.map, w);
    if (ret == EXIT_FAIL) {
        w->evt.end_game(w, EXIT_FAIL);
    } else if (player_block_pos == w->game.map.width - 2) {
        if (!w->game.infinite_mode) {
            w->evt.end_game(w, EXIT_WIN);
        } else
            sfClock_restart(w->game.clock);
    }
    return (&w->game.player);
}

static int player_create_object(player_t *player, sfVector2f *pos,
const char *player_sprite)
{
    sfVector2i sprite_size = PLAYER_SPRITE_SIZE;
    char *sprite_sheet = NULL;

    for (int i = 0; i < NB_PLAYER_SHEET; i++) {
        if (!my_strcmp(player_sprite, PLAYER_OPTION_SPRITE[i])) {
            sprite_sheet = my_strdup(PATH_PLAY_SHEET[i]);
        }
    }
    if (!sprite_sheet) {
        my_putstr_error("\nERROR: invalid player sprite id [option].\n");
        my_putstr_error("\tThe default sprite has been applied.\n");
        sprite_sheet = my_strdup(PATH_PLAY_SHEET[0]);
    }
    player->obj = object_create(sprite_sheet, pos, &sprite_size, P_NB_SPR);
    free(sprite_sheet);
    if (!player->obj)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

player_t *player_create(window_t *w, const char *player_sprite)
{
    player_t *player = &w->game.player;
    sfVector2f pos;
    int block_size = w->game.map.block_size;
    sfVector2f size = {block_size, PLAYER_HEIGHT};

    pos.x = (int)(PLAYER_POSX / block_size) * block_size;
    pos.y = player_get_posy(&w->game.map, w);
    player->destroy = &player_destroy;
    player->display = &player_display;
    player->jump = &player_jump;
    player->set_velocity = &player_set_velocity;
    player->check_collision = &player_check_collision;
    if (pos.y == -1 || player_create_object(player, &pos, player_sprite))
        return NULL;
    player->obj->rescale(player->obj, &size);
    player->obj->set_fps(player->obj, PLAYER_FPMS);
    player->velocity = (sfVector2f){0, 0};
    return player;
}
