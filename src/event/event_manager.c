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
    my_printf("Window size: x %d y %d \n", w->width, w->height);
}

static void manage_keyrelease(window_t *w, sfEvent *event)
{
    if (event->key.code == sfKeyEscape)
        close_window(w);
    else if (event->key.code == sfKeySpace) {
        if (!w->show_menu)
            w->game.player.jump(w);
        else
            event_space_menu(w);
    }
    if (event->key.code == sfKeyP) {
        my_putstr("Key [P]AUSE\n");
        event_pause_menu(w);
    } else if (event->key.code == sfKeyF) {
        event_end_game(w, EXIT_RELOAD);
        close_window(w);
    }
}

static void analyse_events(window_t *w, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        close_window(w);
    if (event->type == sfEvtMouseButtonPressed)
        manage_mouse_click(w, event);
    if (event->type == sfEvtKeyReleased)
        manage_keyrelease(w, event);
    if (event->type == sfEvtResized && w->resize_window == sfTrue)
        event_resize_window(w, event);
}

void event_manager_create(event_manager_t *evt_manager)
{
    evt_manager->exec = &analyse_events;
    evt_manager->mouse_click = &manage_mouse_click;
    evt_manager->key_release = &manage_keyrelease;
    evt_manager->resize = &event_resize_window;
    evt_manager->close = &close_window;
    evt_manager->end_game = &event_end_game;
}
