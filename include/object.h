/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** header
*/

#ifndef H_OBJ
#define H_OBJ

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>

#define GET_TIME(obj) sfClock_getElapsedTime(obj->clock)

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
    struct object *(*display)(struct object *, sfRenderWindow *, sfClock *);
    struct object *(*update_sprite)(struct object *object);
    struct object *(*move)(struct object *object, sfClock *clock);
    struct object *(*set_frame)(struct object *object, int idx_frame);
    struct object *(*set_speed)(struct object *object, double x, double y);
    struct object *(*set_fps)(struct object *object, double frame_per_ms);
    enum object_type type;
    sfClock *clock;
    sfIntRect rect;
    int nb_frame;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f speed;
    sfInt32 frame_per_ms;
    sfInt32 timer_frame;
} object_t;

object_t *object_move(object_t *object, sfClock *clock);

object_t *object_set_frame(object_t *object, int idx_frame);
object_t *object_set_speed(object_t *object, double speedx, double speedy);
object_t *object_set_next_frame(object_t *object);
object_t *object_set_fps(object_t *object, double frame_per_ms);

#endif
