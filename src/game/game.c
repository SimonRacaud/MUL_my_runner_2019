/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** game object
*/

#include "my_runner.h"
#include "game.h"

extern const char *PATH_FONT;
extern const double SPEEDX;

static void game_destroy(game_t *game)
{
    sfClock_destroy(game->clock);
    sfClock_destroy(game->clock_score);
    sfFont_destroy(game->font);
    game->map.destroy(&game->map);
    game->player.destroy(&game->player);
    destroy_element(game);
    game_destroy_panel(game);
}

static game_t *game_display(window_t *w)
{
    float timer = sfTime_asSeconds(sfClock_getElapsedTime(w->game.clock));

    sfRenderWindow_clear(w->window, sfBlack);
    w->game.posx = w->game.speedx * (timer - w->game.sub_time);
    w->game.map.display(w);
    w->game.duck->display(w->game.duck, w->window, w->game.clock);
    w->game.player.display(w);
    game_show_panel(w);
    if ((int)(timer * 10) % 2 == 0)
        game_update_panel(w, &w->game);
    return (&w->game);
}

static void game_create_init(window_t *w, sfBool infinite_mode)
{
    w->game.destroy = &game_destroy;
    w->game.display = &game_display;
    w->game.speedx = SPEEDX;
    w->game.coin_counter = 0;
    w->game.posx = 0;
    w->game.sub_time = 0;
    w->game.bonus_score = 0;
    w->game.infinite_mode = infinite_mode;
}

game_t *game_create(window_t *w, char *pathmap, sfBool infinite_mode,
const char *player_sprite)
{
    game_create_init(w, infinite_mode);
    w->game.clock = sfClock_create();
    w->game.font = sfFont_createFromFile(PATH_FONT);
    w->game.clock_score = sfClock_create();
    if (!map_create(w, pathmap))
        return NULL;
    if (!w->game.font) {
        my_putstr_error("ERROR: load font (in game_t)\n");
        return NULL;
    } else if (!w->game.clock || !w->game.clock_score) {
        my_putstr_error("ERROR: game clock create\n");
        return NULL;
    }
    if (create_elements(&w->game) || !player_create(w, player_sprite)) {
        return NULL;
    } else if (game_create_panel(&w->game) == EXIT_ERROR)
        return NULL;
    return (&w->game);
}
