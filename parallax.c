/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** parallax
*/

#include "my_runner.h"
#include "parallax.h"

static void parallax_set_speed(parallax_t *para, float max_speed)
{
    for (int i = 0; i < 2; i++) {
        para->background[i].set_speed(para->background[i], max_speed / 6, 0);
        para->cloud[i].set_speed(para->background[i], max_speed / 3, 0);
        para->sett01[i].set_speed(para->background[i], max_speed / 2, 0);
        para->sett02[i].set_speed(para->background[i], max_speed, 0);
    }
}

static void parallax_display(parallax_t *parallax, sfRenderWindow *window)
{
    for (int i = 0; i < 2; i++) {
        parallax->background[i].display(parallax->background[i], window);
        parallax->cloud[i].display(parallax->cloud[i], window);
        parallax->sett01[i].display(parallax->sett01[i], window);
        parallax->sett02[i].display(parallax->sett02[i], window);
    }
}

static void parallax_destroy(parallax_t *parallax)
{
    for (int i = 0; i < 2; i++) {
        parallax->background[i].destroy(parallax->background[i]);
        parallax->cloud[i].destroy(parallax->cloud[i]);
        parallax->sett01[i].destroy(parallax->sett01[i]);
        parallax->sett02[i].destroy(parallax->sett02[i]);
    }
}

void parallax_create(parallax_t *parallax, int width, int height)
{
    parallax_t *pa = parallax;
    sfVector2f pos_left = {-width, 0};
    sfVector2f pos_right = {0, 0};

    parallax->size = (sfVector2i){width, height};
    pa->background[0] = object_create(PATH_BG, &pos_left, &pa->size, 1);
    pa->background[1] = object_create(PATH_BG, &pos_right, &pa->size, 1);
    pa->cloud[0] = object_create(PATH_CLOUD, &pos_left, &pa->size, 1);
    pa->cloud[1] = object_create(PATH_CLOUD, &pos_right, &pa->size, 1);
    pa->sett01[0] = object_create(PATH_SETT01, &pos_left, &pa->size, 1);
    pa->sett01[1] = object_create(PATH_SETT01, &pos_right, &pa->size, 1);
    pa->sett02[0] = object_create(PATH_SETT02, &pos_left, &pa->size, 1);
    pa->sett02[1] = object_create(PATH_SETT02, &pos_right, &pa->size, 1);
    parallax_set_speed(&parallax, PARALLAX_SPEED);
    parallax->destroy = &parallax_destroy;
    parallax->display = &parallax_display;
    parallax->set_speed = &parallax_set_speed;
    parallax->move = &parallax_move;
}
