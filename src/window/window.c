/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** window object
*/

#include "my_runner.h"
#include "window.h"

extern const int W_WIDTH;
extern const int W_HEIGHT;
extern const int W_BPP;
extern const int FRAMERATE;
extern const char *TITLE_WINDOW;

static void window_destroy(window_t *w)
{
    sfRenderWindow_destroy(w->window);
    w->game.destroy(&w->game);
    w->menu.destroy(&w->menu);
    w->soundm.destroy(&w->soundm);
}

static window_t *window_display(window_t *w)
{
    if (w->show_menu == sfFalse)
        w->game.display(w);
    else
        w->menu.display(w);
    sfRenderWindow_display(w->window);
    return w;
}

void invert_fullscreen_state(window_t *w)
{
    sfVideoMode mode = {W_WIDTH, W_HEIGHT, W_BPP};

    sfRenderWindow_destroy(w->window);
    w->is_fullscreen = !w->is_fullscreen;
    if (w->is_fullscreen) {
        w->window = sfRenderWindow_create(mode, TITLE_WINDOW, sfClose |
        sfFullscreen | sfResize, NULL);
    } else {
        w->window = sfRenderWindow_create(mode, TITLE_WINDOW, sfClose |
        sfResize, NULL);
    }
    if (!w->window)
        w->evt.close(w);
    else
        sfRenderWindow_setFramerateLimit(w->window, FRAMERATE);
}

static void window_create_init(window_t *w, int width, int height)
{
    w->destroy = window_destroy;
    w->display = window_display;
    w->exit_status = 0;
    w->is_fullscreen = 1;
    w->show_menu = sfTrue;
    w->resize_window = sfFalse;
    w->width = width;
    w->height = height;
}

window_t *window_create(window_t *w, char *path_map, sfBool infinite_mode)
{
    sfVideoMode mode = {W_WIDTH, W_HEIGHT, W_BPP};

    window_create_init(w, mode.width, mode.height);
    w->window = sfRenderWindow_create(mode, TITLE_WINDOW, sfClose |
    sfFullscreen | sfResize, NULL);
    if (!w->window)
        return NULL;
    sfRenderWindow_setFramerateLimit(w->window, FRAMERATE);
    if (!game_create(w, path_map, infinite_mode))
        return NULL;
    else if (!menu_create(w) || !sound_manager_create(&w->soundm))
        return NULL;
    event_manager_create(&w->evt);
    return w;
}
