/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** main
*/

#include "my_runner.h"

static int display(sfEvent *event, window_t *w)
{
    while (sfRenderWindow_isOpen(w->window)) {
        while (sfRenderWindow_pollEvent(w->window, event))
            w->evt.exec(w, event);
        w->display(w);
    }
    if (w->is_reload) {
        w->is_reload = 0;
        invert_fullscreen_state(w);
        display(event, w);
    }
    return EXIT_SUCCESS;
}

int run(char *path_map)
{
    sfEvent event;
    window_t w;

    if (!window_create(&w, path_map)) {
        my_putstr_error("ERROR: create window or sub-objects\n");
        return EXIT_ERROR;
    }
    display(&event, &w);
    w.destroy(&w);
    return EXIT_SUCCESS;
}
