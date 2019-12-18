/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** parallax
*/

#include "my_runner.h"
#include "parallax.h"

static void move_parallax_layer(object_t **layer, parallax_t *parallax,
int layer_id)
{
    layer[1]->pos.x = layer[0]->pos.x + parallax->size.x - 4;
    sfSprite_setPosition(layer[1]->sprite, layer[1]->pos);
    if (layer[1]->pos.x <= 0) {
        sfClock_restart(parallax->clock[layer_id]);
    }
}

parallax_t *parallax_move(parallax_t *parallax)
{
    move_parallax_layer(parallax->background, parallax, 3);
    move_parallax_layer(parallax->cloud, parallax, 2);
    move_parallax_layer(parallax->sett_bg, parallax, 1);
    move_parallax_layer(parallax->sett_fg, parallax, 0);
    return parallax;
}

parallax_t *parallax_set_speed(parallax_t *para, double max_speed)
{
    para->background[0]->set_speed(para->background[0], max_speed / 6, 0);
    para->cloud[0]->set_speed(para->cloud[0], max_speed / 3, 0);
    para->sett_bg[0]->set_speed(para->sett_bg[0], max_speed / 2, 0);
    para->sett_fg[0]->set_speed(para->sett_fg[0], max_speed, 0);
    return para;
}
