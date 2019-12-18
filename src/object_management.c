/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** object
*/

#include "my_runner.h"

object_t *object_move(object_t *object, sfClock *clock)
{
    double timer = sfTime_asSeconds(sfClock_getElapsedTime(clock));

    object->pos.x = object->speed.x * timer;
    object->pos.y = object->speed.y * timer;
    sfSprite_setPosition(object->sprite, object->pos);
    return object;
}
