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
    if (w->exit_status == EXIT_RELOAD) {
        w->exit_status = 0;
        invert_fullscreen_state(w);
        display(event, w);
    } else if (w->exit_status == 0)
        return EXIT_ERROR;
    return w->exit_status;
}

int run(char *path_map)
{
    sfEvent event;
    window_t w;
    int ret;

    if (!window_create(&w, path_map)) {
        my_putstr_error("ERROR: create window or sub-objects\n");
        return EXIT_ERROR;
    }
    ret = display(&event, &w);
    w.destroy(&w);
    if (ret == EXIT_WIN) {
        my_putstr("\nEXIT STATUS: PLAYER WIN\n");
    } else if (ret == EXIT_FAIL) {
        my_putstr("\nEXIT STATUS: PLAYER FAIL\n");
    } else {
        if (ret == EXIT_ERROR)
            my_putstr("\nEXIT STATUS: ERROR/FORCE\n");
    }
    return EXIT_SUCCESS;
}
