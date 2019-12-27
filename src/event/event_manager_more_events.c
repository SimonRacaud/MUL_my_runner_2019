/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** event manager : event functions
*/

#include "my_runner.h"
#include "event_manager.h"

extern const int W_WIDTH;
extern const int W_HEIGHT;
extern const int W_BPP;
extern const int FRAMERATE;
extern const char *TITLE_WINDOW;

void resize_window(window_t *w, sfEvent *event)
{
    w->width = (int)event->size.width;
    w->height = (int)event->size.height;
    map_reload(w);
}

void reload_render_window(window_t *w)
{
    w->is_reload = 1;
    w->evt.close(w);
}
