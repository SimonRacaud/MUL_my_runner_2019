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
extern const double FPMS;

static void game_destroy(game_t *game)
{
    sfClock_destroy(game->clock);
    sfFont_destroy(game->font);
    game->map.destroy(&game->map);
    destroy_element(game);
}

static game_t *game_display(window_t *w)
{
    w->game.timer += sfClock_getElapsedTime(w->game.clock).microseconds;
    if (w->game.timer >= w->game.fpms) {
        w->game.timer -= w->game.fpms;
        w->game.posx += w->game.speedx;
        w->game.map.display(w);
        w->game.duck->display(w->game.duck, w->window, w->game.clock);
    }
    sfClock_restart(w->game.clock);
    return (&w->game);
}

game_t *game_create(window_t *w, char *pathmap)
{
    w->game.destroy = &game_destroy;
    w->game.display = &game_display;
    w->game.clock = sfClock_create();
    w->game.font = sfFont_createFromFile(PATH_FONT);
    w->game.speedx = SPEEDX;
    w->game.posx = 0;
    w->game.fpms = FPMS;
    w->game.timer = 0;
    if (!map_create(w, pathmap))
        return NULL;
    if (!w->game.font) {
        my_putstr_error("ERROR: load font\n");
        return NULL;
    }
    if (create_elements(&w->game))
        return NULL;
    return (&w->game);
}
