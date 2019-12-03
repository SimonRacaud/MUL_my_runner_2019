/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** object
*/

#include "my_runner.h"

void object_set_speed(object_t *object, float speedx, float speedy)
{
    object->speed.x = speedx;
    object->speed.y = speedy;
}
