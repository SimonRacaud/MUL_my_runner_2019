/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** main
*/

#include "my_runner.h"

int main(void)
{
    sfEvent event;
    window_t *w = create_window();

    if (!w)
        return -1;
    while (sfRenderWindow_isOpen(w->window)) {
        while (sfRenderWindow_pollEvent(w->window, &event))
            analyse_events(w, &event);
        display(w);
    }
    destroy_window(w);
    return 0;
}
