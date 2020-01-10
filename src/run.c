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
        w->exit_status = EXIT_SUCCESS;
        invert_fullscreen_state(w);
        display(event, w);
    }
    return w->exit_status;
}

static void display_exit_state(int ret, window_t *w)
{
    my_printf("\n%s\nCoin: %d\n", w->game.txt_score, w->game.coin_counter);
    if (ret == EXIT_WIN) {
        my_putstr("\nEXIT STATUS: PLAYER WIN\n");
    } else if (ret == EXIT_FAIL) {
        my_putstr("\nEXIT STATUS: PLAYER FAIL\n");
    } else {
        if (ret == EXIT_ERROR)
            my_putstr("\nEXIT STATUS: EXIT ERROR\n");
        else
            my_putstr("\nEXIT STATUS: EXIT SUCCESS\n");
    }
    my_putchar('\n');
}

int run(char *path_map, sfBool infinite_mode)
{
    sfEvent event;
    window_t w;
    int ret;

    if (!window_create(&w, path_map, infinite_mode)) {
        my_putstr_error("ERROR: create window or sub-objects\n");
        return EXIT_ERROR;
    }
    w.soundm.play(&w.soundm, SOUND_THEME);
    ret = display(&event, &w);
    display_exit_state(ret, &w);
    w.destroy(&w);
    if (ret == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
