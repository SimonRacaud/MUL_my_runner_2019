/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** header
*/

#ifndef H_PARALLAX
#define H_PARALLAX

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include "object.h"

typedef struct parallax {
    void (*destroy)(struct parallax *paral);
    struct parallax *(*display)(struct parallax *, sfRenderWindow *, sfClock *);
    struct parallax *(*set_speed_mps)(struct parallax *, double, double);
    struct parallax *(*move)(struct parallax *paral);
    object_t *background[2];
    object_t *cloud[2];
    object_t *sett01[2];
    object_t *sett02[2];
    char *path_bg;
    char *path_cloud;
    char *path_sett01;
    char *path_sett02;
    sfVector2i size;
} parallax_t;

parallax_t *parallax_move(parallax_t *parallax);
parallax_t *parallax_set_speed_mps(parallax_t *para, double max_speed,
double mps);

#endif
