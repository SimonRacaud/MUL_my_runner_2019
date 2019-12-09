/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** window object
*/

#include "my_runner.h"
#include "window.h"

static void window_destroy(window_t *w)
{
    sfRenderWindow_destroy(w->window);
    sfClock_destroy(w->timer);
    w->game.destroy(w->game);
    w->evt.destroy(w->evt);
    //destroy_parallax(&w->parallax);
    free(w);
}

static window_t *window_display(window_t *w)
{

}

window_t *window_create(void)
{
    window_t *w = malloc(sizeof(window_t));
    sfVideoMode mode = {W_WIDTH, W_HEIGHT, W_BPP};

    w->destroy = window_destroy;
    w->display = window_display;
    w->window = sfRenderWindow_create(mode, TITLE_WINDOW, sfClose |
    sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(w->window, FRAMERATE);
    w->width = mode.width;
    w->height = mode.height;
    if (!w->window)
        return NULL;
}
