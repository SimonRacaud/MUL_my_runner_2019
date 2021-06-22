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
#define SET_FPS(obj, fpms) obj->set_fps(obj, fpms)

enum object_type {
    DEFAULT,
    IMG,
    PLAYER,
    ENEMY,
    BLOCK_ROCK,
    BLOCK_GROUND,
    BLOCK_PLATFORM,
    BLOCK_EMPTY,
    BLOCK_EMPTY_TXR,
    BLOCK_TRAP,
    BLOCK_COIN,
    BLOCK_MALUS
};

typedef enum object_type object_type_e;

typedef struct object {
    void (*destroy)(struct object *object);
    struct object *(*display)(struct object *, sfRenderWindow *, sfClock *);
    struct object *(*update_sprite)(struct object *object);
    struct object *(*move)(struct object *object, sfClock *clock);
    struct object *(*rescale)(struct object *object, sfVector2f *new_size);
    struct object *(*set_frame)(struct object *object, int idx_frame);
    struct object *(*set_speed)(struct object *object, double x, double y);
    struct object *(*set_fps)(struct object *object, sfInt32 frame_per_ms);
    enum object_type type;
    sfClock *clock;
    sfIntRect rect;
    int nb_frame;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f speed;
    sfVector2f size;
    sfInt32 frame_per_ms;
    sfInt32 timer_frame;
} object_t;

object_t *object_move(object_t *object, sfClock *clock);

object_t *object_rescale(object_t *object, sfVector2f *new_size);
object_t *object_set_frame(object_t *object, int idx_frame);
object_t *object_set_speed(object_t *object, double speedx, double speedy);
object_t *object_set_next_frame(object_t *object);
object_t *object_set_fps(object_t *object, sfInt32 frame_per_ms);

#endif
