/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** object
*/

#include "my_runner.h"

object_t *object_set_speed(object_t *object, double speedx, double speedy)
{
    object->speed.x = speedx;
    object->speed.y = speedy;
    return object;
}

object_t *object_move(object_t *object, sfClock *clock)
{
    int nb_movement = 0;

    if (object->mov_per_ms == 0) {
        object->pos.x += object->speed.x;
        object->pos.y += object->speed.y;
        sfSprite_setPosition(object->sprite, object->pos);
        return object;
    }
    object->timer_position += sfClock_getElapsedTime(clock).microseconds;
    if (object->timer_position >= (object->mov_per_ms * 1000)) {
        nb_movement = object->timer_position / (object->mov_per_ms * 1000);
        object->timer_position -= (nb_movement * (object->mov_per_ms * 1000));
        for (int i = 0; i < nb_movement; i++) {
            object->pos.x += object->speed.x;
            object->pos.y += object->speed.y;
        }
        sfSprite_setPosition(object->sprite, object->pos);
    }
    return object;
}

object_t *object_set_fps(object_t *object, double frame_per_ms)
{
    object->frame_per_ms = frame_per_ms;
    return object;
}

object_t *object_set_mps(object_t *object, double movement_per_ms)
{
    object->frame_per_ms = movement_per_ms;
    return object;
}

object_t *object_set_next_frame(object_t *object)
{
    object->rect.left += object->rect.width;
    if (object->rect.left == object->rect.width * object->nb_frame)
        object->rect.left = 0;
    return object;
}
