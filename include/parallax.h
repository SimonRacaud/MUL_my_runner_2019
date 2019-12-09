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

static const char *PATH_SETT01 = "asset/setting01.png";
static const char *PATH_SETT02 = "asset/setting02.png";
static const char *PATH_CLOUD = "asset/clouds.png";
static const char *PATH_BG = "asset/background.png";

typedef struct parallax {
    void (*destroy)(parallax_t *paral);
    parallax_t *(*display)(parallax_t *paral, sfRenderWindow *window);
    parallax_t *(*set_speed)(parallax_t *paral, float max_speed);
    parallax_t *(*move)(parallax_t *paral);
    object_t *background[2];
    object_t *cloud[2];
    object_t *sett01[2];
    object_t *sett02[2];
    sfVector2i size;
} parallax_t;

void parallax_move(window_t *w);

#endif
