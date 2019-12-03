/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** event manager
*/

#include "my_runner.h"

static void close_window(window_t *w)
{
    sfRenderWindow_close(w->window);
}

static void manage_mouse_click(window_t *w, sfEvent *event)
{

}

void analyse_events(window_t *w, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        close_window(w);
    if (event->type == sfEvtMouseButtonPressed)
        manage_mouse_click(w, event);
}
