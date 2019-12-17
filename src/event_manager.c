/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** event manager
*/

#include "my_runner.h"
#include "event_manager.h"

static void close_window(window_t *w)
{
    sfRenderWindow_close(w->window);
}

static void manage_mouse_click(window_t *w, sfEvent *event)
{
    sfMouseButtonEvent evt = event->mouseButton;

    my_printf("Mouse click: x %d y %d \n", evt.x, evt.y);
}

static void manage_keyrelease(window_t *w, sfEvent *event)
{
    if (event->key.code == sfKeyEscape)
        close_window(w);
    else if (event->key.code == sfKeySpace)
        my_putstr("KEY SPACE\n");
    if (event->key.code == sfKeyLeft)
        my_putstr("Key LEFT\n");
    else if (event->key.code == sfKeyRight)
        my_putstr("Key RIGHT\n");
    if (event->key.code == sfKeyUp)
        my_putstr("Key UP\n");
    else if (event->key.code == sfKeyDown)
        my_putstr("Key DOWN\n");
}

static void analyse_events(window_t *w, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        close_window(w);
    if (event->type == sfEvtMouseButtonPressed)
        manage_mouse_click(w, event);
    if (event->type == sfEvtKeyReleased)
        manage_keyrelease(w, event);
}

void event_manager_create(event_manager_t *evt_manager)
{
    evt_manager->exec = &analyse_events;
    evt_manager->mouse_click = &manage_mouse_click;
    evt_manager->key_release = &manage_keyrelease;
    evt_manager->close = &close_window;
}
