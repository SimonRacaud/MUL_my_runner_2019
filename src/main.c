/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** main
*/

#include "my_runner.h"

static void event_manager(window_t *w, sfEvent *e)
{
    if (e->type == sfEvtClosed)
        sfRenderWindow_close(w->window);
    else if (e->type == sfEvtMouseMoved)
        //
}

int main(void)
{
    sfEvent event;
    window_t *w = create_window();

    create_el_window(w);
    if (!w)
        return -1;
    while (sfRenderWindow_isOpen(w->window)) {
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event);
        display(w);
    }
    destroy_window(w);
    return 0;
}
