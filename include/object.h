/*
** EPITECH PROJECT, 2019
** csfml_2019
** File description:
** header
*/

#ifndef H_OBJ
#define H_OBJ

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>

enum object_type {
    DEFAULT,
    IMG,
    PLAYER,
    ENEMY,
    COIN,
    BLOCK
};

typedef struct object {
    void (*destroy)(object_t *object);
    object_t *(*display)(object_t *object, sfRenderWindow *window);
    object_t *(*update_sprite)(object_t *object);
    object_t *(*move)(object_t *object);
    object_t *(*set_speed)(object_t *object, doube x, double y);
    enum object_type type;
    sfIntRect rect;
    int nb_frame;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f speed;
} object_t;

void object_set_speed(object_t *object, float speedx, float speedy);
void object_move(object_t *object, float x, float y);

#endif
