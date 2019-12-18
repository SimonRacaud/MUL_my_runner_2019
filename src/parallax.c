/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** parallax
*/

#include "my_runner.h"
#include "parallax.h"

extern const char *PATH_SETT_BG;
extern const char *PATH_SETT_FG;
extern const char *PATH_CLOUD;
extern const char *PATH_BG;
extern const int PARALLAX_T_SX;
extern const int PARALLAX_T_SY;

static parallax_t *parallax_display(parallax_t *parallax,
sfRenderWindow *window)
{
    sfClock **clock = parallax->clock;

    DISPLAY(parallax->background[0], window, clock[3]);
    DISPLAY(parallax->background[1], window, clock[3]);
    DISPLAY(parallax->cloud[0], window, clock[2]);
    DISPLAY(parallax->cloud[1], window, clock[2]);
    DISPLAY(parallax->sett_bg[0], window, clock[1]);
    DISPLAY(parallax->sett_bg[1], window, clock[1]);
    DISPLAY(parallax->sett_fg[0], window, clock[0]);
    DISPLAY(parallax->sett_fg[1], window, clock[0]);
    parallax->move(parallax);
    return parallax;
}

static void parallax_destroy(parallax_t *parallax)
{
    for (int i = 0; i < 2; i++) {
        parallax->background[i]->destroy(parallax->background[i]);
        parallax->cloud[i]->destroy(parallax->cloud[i]);
        parallax->sett_bg[i]->destroy(parallax->sett_bg[i]);
        parallax->sett_fg[i]->destroy(parallax->sett_fg[i]);
    }
    free(parallax->path_bg);
    free(parallax->path_cloud);
    free(parallax->path_settb);
    free(parallax->path_settf);
    for (int i = 0; i < 4; i++)
        sfClock_destroy(parallax->clock[i]);
}

static void parallax_init_path(parallax_t *para)
{
    para->path_bg = my_strdup(PATH_BG);
    para->path_cloud = my_strdup(PATH_CLOUD);
    para->path_settb = my_strdup(PATH_SETT_BG);
    para->path_settf = my_strdup(PATH_SETT_FG);
    for (int i = 0; i < 4; i++)
        para->clock[i] = sfClock_create();
}

void parallax_create(window_t *w, int width, int height)
{
    parallax_t *pa = &w->game.map.parallax;
    sfVector2f pos_left = {0, 0};
    sfVector2f pos_right = {width, 0};

    parallax_init_path(pa);
    w->game.map.parallax.size = (sfVector2i){PARALLAX_T_SX, PARALLAX_T_SY};
    pa->background[0] = object_create(pa->path_bg, &pos_left, &pa->size, 1);
    pa->background[1] = object_create(pa->path_bg, &pos_right, &pa->size, 1);
    pa->cloud[0] = object_create(pa->path_cloud, &pos_left, &pa->size, 1);
    pa->cloud[1] = object_create(pa->path_cloud, &pos_right, &pa->size, 1);
    pa->sett_bg[0] = object_create(pa->path_settb, &pos_left, &pa->size, 1);
    pa->sett_bg[1] = object_create(pa->path_settb, &pos_right, &pa->size, 1);
    pa->sett_fg[0] = object_create(pa->path_settf, &pos_left, &pa->size, 1);
    pa->sett_fg[1] = object_create(pa->path_settf, &pos_right, &pa->size, 1);
    parallax_set_speed(pa, -w->game.speedx);
    parallax_scale(pa, w);
    w->game.map.parallax.destroy = &parallax_destroy;
    w->game.map.parallax.display = &parallax_display;
    w->game.map.parallax.set_speed = &parallax_set_speed;
    w->game.map.parallax.move = &parallax_move;
}
