/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** main
*/

#include "my_runner.h"

int run(char *path_map)
{
    sfEvent event;
    window_t w;

    if (!window_create(&w, path_map)) {
        my_putstr_error("ERROR: create window or sub-objects\n");
        return EXIT_ERROR;
    }
    while (sfRenderWindow_isOpen(w.window)) {
        while (sfRenderWindow_pollEvent(w.window, &event))
            w.evt.exec(&w, &event);
        w.display(&w);
    }
    w.destroy(&w);
    return EXIT_SUCCESS;
}
