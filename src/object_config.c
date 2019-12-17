/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** object
*/

#include "my_runner.h"

object_t *object_set_frame(object_t *object, int idx_frame)
{
    if (idx_frame < object->nb_frame && idx_frame >= 0) {
        object->rect.left = idx_frame * object->rect.width;
        sfSprite_setTextureRect(object->sprite, object->rect);
    } else {
        my_putstr_error("WARNING: object_set_frame: invalid idx of frame\n");
    }
    return object;
}

object_t *object_set_speed(object_t *object, double speedx, double speedy)
{
    object->speed.x = speedx;
    object->speed.y = speedy;
    return object;
}

object_t *object_set_fps(object_t *object, double frame_per_ms)
{
    object->frame_per_ms = frame_per_ms;
    return object;
}

object_t *object_set_mps(object_t *object, double movement_per_ms)
{
    object->mov_per_ms = movement_per_ms;
    return object;
}

object_t *object_set_next_frame(object_t *object)
{
    object->rect.left += object->rect.width;
    if (object->rect.left == object->rect.width * object->nb_frame)
        object->rect.left = 0;
    return object;
}
