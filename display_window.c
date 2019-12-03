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
    sfRenderWindow_drawSprite(w->window, w->duck->sprite, NULL);
    if (sfClock_getElapsedTime(w->timer).microseconds > 100000) {
        update_frame_object(w->duck);
        sfClock_restart(w->timer);
    }
    display_parallax(&w->parallax, w->window);
    w->duck->pos.x++;
    w->duck->pos.y++;
    sfSprite_setPosition(w->duck->sprite, w->duck->pos);
    //sfRenderWindow_drawText(w->window, w->txt_, NULL);
    //sfRenderWindow_drawRectangleShape(w->window, w->rectangle, NULL);
    sfRenderWindow_display(w->window);
    return 0;
}
