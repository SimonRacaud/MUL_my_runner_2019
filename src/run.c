/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** main
*/

#include "my_runner.h"

static int display(sfEvent *event, window_t *w)
{
    w->soundm.play(&w->soundm, SOUND_THEME);
    while (sfRenderWindow_isOpen(w->window)) {
        while (sfRenderWindow_pollEvent(w->window, event))
            w->evt.exec(w, event);
        w->display(w);
    }
    if (w->exit_status == EXIT_RELOAD) {
        w->exit_status = 0;
        w->resize_window = sfTrue;
        invert_fullscreen_state(w);
        display(event, w);
    } else if (w->exit_status == 0) {
        return EXIT_ERROR;
    }
    if (w->exit_status == EXIT_FAIL)
        w->soundm.play(&w->soundm, SOUND_DIE);
    else if (w->exit_status == EXIT_WIN)
        w->soundm.play(&w->soundm, SOUND_WIN);
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
            my_putstr("\nEXIT STATUS: ERROR or FORCED(escape)\n");
    }
    return EXIT_SUCCESS;
}
