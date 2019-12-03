/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** display window
*/

#include "my_runner.h"

int display(window_t *w)
{
    sfRenderWindow_clear(w->window, sfBlack);
    if (sfClock_getElapsedTime(w->timer).microseconds > 100000) {
        update_frame_object(w->duck);
        sfClock_restart(w->timer);
    }
    move_parallax(w);
    display_parallax(&w->parallax, w->window);
    //
    w->duck->pos.x++;
    w->duck->pos.y++;
    display_object(w->duck, w->window);
    //
    sfRenderWindow_display(w->window);
    return 0;
}
