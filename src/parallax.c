/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** parallax
*/

#include "my_runner.h"

static void init_parallax(parallax_t *para)
{
    object_set_speed(para->background[0], 0.5, 0);
    object_set_speed(para->background[1], 0.5, 0);
    object_set_speed(para->cloud[0], 1, 0);
    object_set_speed(para->cloud[1], 1, 0);
    object_set_speed(para->sett01[0], 2, 0);
    object_set_speed(para->sett01[1], 2, 0);
    object_set_speed(para->sett02[0], 3, 0);
    object_set_speed(para->sett02[1], 3, 0);
}

void create_parallax(char *path_bg, char *path_cloud,
char *path_sett[2], window_t *w)
{
    parallax_t *pa = &w->parallax;
    sfVector2f pos_left = {-w->width, 0};
    sfVector2f pos_right = {0, 0};
    sfVector2i size = {w->width, w->height};

    pa->background[0] = create_object(path_bg, &pos_left, &size, 1);
    pa->background[1] = create_object(path_bg, &pos_right, &size, 1);
    if (path_cloud[0] != '\0') {
        pa->cloud[0] = create_object(path_cloud, &pos_left, &size, 1);
        pa->cloud[1] = create_object(path_cloud, &pos_right, &size, 1);
    }
    if (path_sett[0][0] != '\0') {
        pa->sett01[0] = create_object(path_sett[0], &pos_left, &size, 1);
        pa->sett01[1] = create_object(path_sett[0], &pos_right, &size, 1);
    }
    if (path_sett[1][0] != '\0') {
        pa->sett02[0] = create_object(path_sett[1], &pos_left, &size, 1);
        pa->sett02[1] = create_object(path_sett[1]  , &pos_right, &size, 1);
    }
    init_parallax(&w->parallax);
}

static void move_parallax_layer(object_t **layer, window_t *w)
{
    layer[0]->pos.x += layer[0]->speed.x;
    layer[1]->pos.x += layer[0]->speed.x;
    if (layer[1]->pos.x > w->width) {
        layer[0]->pos.x = 0 - w->width;
        layer[1]->pos.x;
    }
}

void move_parallax(float max_speed, window_t *w)
{
    move_parallax_layer(w->parallax.background, w);
    move_parallax_layer(w->parallax.cloud, w);
    move_parallax_layer(w->parallax.sett01, w);
    move_parallax_layer(w->parallax.sett02, w);
}

void destroy_parallax(parallax_t *parallax)
{
    destroy_object(parallax->background[0]);
    destroy_object(parallax->background[1]);
    destroy_object(parallax->cloud[0]);
    destroy_object(parallax->cloud[1]);
    destroy_object(parallax->sett01[0]);
    destroy_object(parallax->sett01[1]);
    destroy_object(parallax->sett02[0]);
    destroy_object(parallax->sett02[1]);
}
