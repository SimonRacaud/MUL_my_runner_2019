/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** parallax
*/

#include "my_runner.h"

static void move_parallax_layer(object_t **layer, window_t *w)
{
    layer[0]->pos.x += layer[0]->speed.x;
    layer[1]->pos.x += layer[1]->speed.x;
    if (layer[1]->pos.x > w->width) {
        layer[0]->pos.x = (0 - w->width);
        layer[1]->pos.x = 0;
    }
}

void move_parallax(window_t *w)
{
    move_parallax_layer(w->parallax.background, w);
    move_parallax_layer(w->parallax.cloud, w);
    move_parallax_layer(w->parallax.sett01, w);
    move_parallax_layer(w->parallax.sett02, w);
}
