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
    void (*destroy)(struct object *object);
    struct object *(*display)(struct object *object, sfRenderWindow *window);
    struct object *(*update_sprite)(struct object *object);
    struct object *(*move)(struct object *object);
    struct object *(*set_speed)(struct object *object, double x, double y);
    enum object_type type;
    sfIntRect rect;
    int nb_frame;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f speed;
} object_t;

object_t *object_set_speed(object_t *object, double speedx, double speedy);
object_t *object_move(object_t *object);

#endif
