/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** parallax
*/

#include "my_runner.h"
#include "parallax.h"

static void move_parallax_layer(object_t **layer, parallax_t *paral)
{
    layer[0]->pos.x += layer[0]->speed.x;
    layer[1]->pos.x += layer[1]->speed.x;
    if (layer[1]->pos.x > paral->size.x) {
        layer[0]->pos.x = (0 - paral->size.x);
        layer[1]->pos.x = 0;
    }
}

void parallax_move(parallax_t *paral)
{
    move_parallax_layer(paral->background, paral);
    move_parallax_layer(paral->cloud, paral;
    move_parallax_layer(paral->sett01, paral);
    move_parallax_layer(paral->sett02, paral);
}
