/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** parallax
*/

#include "my_runner.h"

void parallax_set_speed(parallax_t *para, float max_speed)
{
    object_set_speed(para->background[0], max_speed / 6, 0);
    object_set_speed(para->background[1], max_speed / 6, 0);
    object_set_speed(para->cloud[0], max_speed / 3, 0);
    object_set_speed(para->cloud[1], max_speed / 3, 0);
    object_set_speed(para->sett01[0], max_speed / 2, 0);
    object_set_speed(para->sett01[1], max_speed / 2, 0);
    object_set_speed(para->sett02[0], max_speed, 0);
    object_set_speed(para->sett02[1], max_speed, 0);
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
    pa->cloud[0] = create_object(path_cloud, &pos_left, &size, 1);
    pa->cloud[1] = create_object(path_cloud, &pos_right, &size, 1);
    pa->sett01[0] = create_object(path_sett[0], &pos_left, &size, 1);
    pa->sett01[1] = create_object(path_sett[0], &pos_right, &size, 1);
    pa->sett02[0] = create_object(path_sett[1], &pos_left, &size, 1);
    pa->sett02[1] = create_object(path_sett[1]  , &pos_right, &size, 1);
    parallax_set_speed(&w->parallax, 3);
}

void display_parallax(parallax_t *parallax, sfRenderWindow *window)
{
    display_object(parallax->background[0], window);
    display_object(parallax->background[1], window);
    display_object(parallax->cloud[0], window);
    display_object(parallax->cloud[1], window);
    display_object(parallax->sett01[0], window);
    display_object(parallax->sett01[1], window);
    display_object(parallax->sett02[0], window);
    display_object(parallax->sett02[1], window);
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
