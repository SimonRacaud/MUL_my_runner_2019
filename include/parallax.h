/*
** EPITECH PROJECT, 2019
** csfml_2019
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
    struct parallax *(*display)(struct parallax *, sfRenderWindow *);
    struct parallax *(*set_speed)(struct parallax *paral, float max_speed);
    struct parallax *(*move)(struct parallax *paral);
    object_t *background[2];
    object_t *cloud[2];
    object_t *sett01[2];
    object_t *sett02[2];
    sfVector2i size;
} parallax_t;

parallax_t *parallax_move(parallax_t *paral);

#endif
