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
    layer[1]->pos.x = layer[0]->pos.x + paral->size.x - 4;
    if (layer[0]->pos.x <= (-paral->size.x)) {
        layer[0]->pos.x = 0;
        layer[1]->pos.x = paral->size.x;
        sfSprite_setPosition(layer[0]->sprite, layer[0]->pos);
    }
    sfSprite_setPosition(layer[1]->sprite, layer[1]->pos);
}

parallax_t *parallax_move(parallax_t *parallax)
{
    move_parallax_layer(parallax->background, parallax);
    move_parallax_layer(parallax->cloud, parallax);
    move_parallax_layer(parallax->sett01, parallax);
    move_parallax_layer(parallax->sett02, parallax);
    return parallax;
}

parallax_t *parallax_set_speed(parallax_t *para, double max_speed)
{
    para->background[0]->set_speed(para->background[0], max_speed / 6, 0);
    para->cloud[0]->set_speed(para->cloud[0], max_speed / 3, 0);
    para->sett01[0]->set_speed(para->sett01[0], max_speed / 2, 0);
    para->sett02[0]->set_speed(para->sett02[0], max_speed, 0);
    return para;
}
