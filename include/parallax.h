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

#define DISPLAY(obj, window, clock) obj->display(obj, window, clock)

typedef struct parallax {
    void (*destroy)(struct parallax *paral);
    struct parallax *(*display)(struct parallax *, sfRenderWindow *);
    struct parallax *(*set_speed)(struct parallax *, double);
    struct parallax *(*move)(struct parallax *paral);
    sfClock *clock[4];
    object_t *background[2];
    object_t *cloud[2];
    object_t *sett_bg[2];
    object_t *sett_fg[2];
    char *path_bg;
    char *path_cloud;
    char *path_settb;
    char *path_settf;
    sfVector2i size;
} parallax_t;

parallax_t *parallax_move(parallax_t *parallax);
parallax_t *parallax_set_speed(parallax_t *para, double max_speed);

#endif
