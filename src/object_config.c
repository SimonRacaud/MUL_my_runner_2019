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

object_t *object_move(object_t *object)
{
    object->pos.x += object->speed.x;
    object->pos.y += object->speed.y;
    sfSprite_setPosition(object->sprite, object->pos);
    return object;
}
