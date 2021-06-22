/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** object
*/

#include "my_runner.h"

object_t *object_rescale(object_t *object, sfVector2f *new_size)
{
    sfVector2f scale;

    scale.x = (float)new_size->x / object->rect.width;
    scale.y = (float)new_size->y / object->rect.height;
    object->size = (*new_size);
    sfSprite_setScale(object->sprite, scale);
    return object;
}

object_t *object_set_frame(object_t *object, int idx_frame)
{
    object->rect.left = idx_frame * object->rect.width;
    sfSprite_setTextureRect(object->sprite, object->rect);
    if (idx_frame < 0)
        my_putstr_error("WARNING: object_set_frame: invalid idx of frame\n");
    return object;
}

object_t *object_set_speed(object_t *object, double speedx, double speedy)
{
    object->speed.x = speedx;
    object->speed.y = speedy;
    return object;
}

object_t *object_set_fps(object_t *object, sfInt32 frame_per_ms)
{
    object->frame_per_ms = frame_per_ms;
    if (object->clock == NULL)
        object->clock = sfClock_create();
    return object;
}

object_t *object_set_next_frame(object_t *object)
{
    object->rect.left += object->rect.width;
    if (object->rect.left >= object->rect.width * object->nb_frame)
        object->rect.left = 0;
    return object;
}
