/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** parallax
*/

#include "my_runner.h"
#include "parallax.h"

static void move_parallax_layer(object_t **layer, parallax_t *paral,
sfClock *clock)
{
    layer[0]->move(layer[0], clock);
    layer[1]->move(layer[1], clock);
    if (layer[1]->pos.x > paral->size.x) {
        layer[0]->pos.x = (0 - paral->size.x);
        layer[1]->pos.x = 0;
    }
}

parallax_t *parallax_move(parallax_t *paral, sfClock *clock)
{
    move_parallax_layer(paral->background, paral, clock);
    move_parallax_layer(paral->cloud, paral, clock);
    move_parallax_layer(paral->sett01, paral, clock);
    move_parallax_layer(paral->sett02, paral, clock);
    return paral;
}

parallax_t *parallax_set_speed_mps(parallax_t *para, double max_speed,
double mps)
{
    for (int i = 0; i < 2; i++) {
        para->background[i]->set_speed(para->background[i], max_speed / 6, 0);
        para->background[i]->set_mps(para->background[i], mps);
        para->cloud[i]->set_speed(para->cloud[i], max_speed / 3, 0);
        para->cloud[i]->set_mps(para->cloud[i], mps);
        para->sett01[i]->set_speed(para->sett01[i], max_speed / 2, 0);
        para->sett01[i]->set_mps(para->sett01[i], mps);
        para->sett02[i]->set_speed(para->sett02[i], max_speed, 0);
        para->sett02[i]->set_mps(para->sett02[i], mps);
    }
    return para;
}
