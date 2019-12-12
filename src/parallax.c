/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** parallax
*/

#include "my_runner.h"
#include "parallax.h"

extern const char *PATH_SETT01;
extern const char *PATH_SETT02;
extern const char *PATH_CLOUD;
extern const char *PATH_BG;
extern const double PARALLAX_MPS;

static parallax_t *parallax_display(parallax_t *parallax,
sfRenderWindow *window)
{
    parallax->background[0]->display(parallax->background[0], window);
    parallax->background[1]->display(parallax->background[1], window);
    parallax->cloud[0]->display(parallax->cloud[0], window);
    parallax->cloud[1]->display(parallax->cloud[1], window);
    parallax->sett01[0]->display(parallax->sett01[0], window);
    parallax->sett01[1]->display(parallax->sett01[1], window);
    parallax->sett02[0]->display(parallax->sett02[0], window);
    parallax->sett02[1]->display(parallax->sett02[1], window);
    return parallax;
}

static void parallax_destroy(parallax_t *parallax)
{
    for (int i = 0; i < 2; i++) {
        parallax->background[i]->destroy(parallax->background[i]);
        parallax->cloud[i]->destroy(parallax->cloud[i]);
        parallax->sett01[i]->destroy(parallax->sett01[i]);
        parallax->sett02[i]->destroy(parallax->sett02[i]);
    }
    free(parallax->path_bg);
    free(parallax->path_cloud);
    free(parallax->path_sett01);
    free(parallax->path_sett02);
}

static void parallax_init_path(parallax_t *para)
{
    para->path_bg = my_strdup(PATH_BG);
    para->path_cloud = my_strdup(PATH_CLOUD);
    para->path_sett01 = my_strdup(PATH_SETT01);
    para->path_sett02 = my_strdup(PATH_SETT02);
}

void parallax_create(window_t *w, int width, int height)
{
    parallax_t *pa = &w->game.map.parallax;
    sfVector2f pos_left = {-width, 0};
    sfVector2f pos_right = {0, 0};

    parallax_init_path(pa);
    w->game.map.parallax.size = (sfVector2i){width, height};
    pa->background[0] = object_create(pa->path_bg, &pos_left, &pa->size, 1);
    pa->background[1] = object_create(pa->path_bg, &pos_right, &pa->size, 1);
    pa->cloud[0] = object_create(pa->path_cloud, &pos_left, &pa->size, 1);
    pa->cloud[1] = object_create(pa->path_cloud, &pos_right, &pa->size, 1);
    pa->sett01[0] = object_create(pa->path_sett01, &pos_left, &pa->size, 1);
    pa->sett01[1] = object_create(pa->path_sett01, &pos_right, &pa->size, 1);
    pa->sett02[0] = object_create(pa->path_sett02, &pos_left, &pa->size, 1);
    pa->sett02[1] = object_create(pa->path_sett02, &pos_right, &pa->size, 1);
    parallax_set_speed_mps(pa, w->game.speedx, PARALLAX_MPS);
    w->game.map.parallax.destroy = &parallax_destroy;
    w->game.map.parallax.display = &parallax_display;
    w->game.map.parallax.set_speed_mps = &parallax_set_speed_mps;
    w->game.map.parallax.move = &parallax_move;
}
