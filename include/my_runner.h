/*
** EPITECH PROJECT, 2019
** csfml_2019
** File description:
** header
*/

#ifndef H_RUNNER
#define H_RUNNER

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <math.h>
#include "my.h"

#define PATH_FONT ""
#define CHAR_SIZE 0
#define W_WIDTH 1280
#define W_HEIGHT 720
static const int framerate_g = 60;

typedef struct object {
    enum {OTHER, IMAGE, DUCK} type;
    sfIntRect rect;
    int nb_frame;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f speed;
} object_t;

typedef struct parallax {
    object_t *background[2];
    object_t *cloud[2];
    object_t *sett01[2];
    object_t *sett02[2];
} parallax_t;

typedef struct window {
    sfRenderWindow *window;
    int width;
    int height;
    sfClock *timer;
    sfFont *font;
    object_t *duck;
    parallax_t parallax;
} window_t;

void analyse_events(window_t *w, sfEvent *event);

window_t *create_window(void);
void destroy_window(window_t *w);
int display(window_t *w);

object_t *create_object(char *spritesheet_path, sfVector2f *pos,
sfVector2i *size, int nb_frame);
void destroy_object(object_t *object);
void update_frame_object(object_t *object);
void move_object(object_t *object_t, float x, float y);
void object_set_speed(object_t *object, float speedx, float speedy);
void display_object(object_t *object, sfRenderWindow *window);

void create_parallax(char *path_bg, char *path_cloud,
char *path_sett[2], window_t *w);
void destroy_parallax(parallax_t *parallax);
void move_parallax(float max_speed, window_t *w);
void display_parallax(parallax_t *parallax, sfRenderWindow *window);

#endif
