/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** object
*/

#include "my_runner.h"

object_t *create_object(char *spritesheet_path, sfVector2f *pos,
sfVector2i *size, int nb_frame)
{
    object_t *object = malloc(sizeof(object_t));

    object->texture = sfTexture_createFromFile(spritesheet_path, NULL);
    object->sprite = sfSprite_create();
    if (!object->texture || !object->sprite || !object) {
        my_putstr_error("Error: create_duck\n");
        free(object);
        return NULL;
    }
    object->rect = (sfIntRect){0, 0, size->x, size->y};
    object->nb_frame = nb_frame;
    object->type = OTHER;
    object->speed = (sfVector2f){0.0f, 0.0f};
    sfSprite_setTexture(object->sprite, object->texture, sfFalse);
    sfSprite_setTextureRect(object->sprite, object->rect);
    sfSprite_setPosition(object->sprite, *pos);
    return object;
}

void object_set_speed(object_t *object, float speedx, float speedy)
{
    object->speed.x = speedx;
    object->speed.y = speedy;
}

void display_object(object_t *object, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, object->sprite, NULL);
}

void destroy_object(object_t *object)
{
    sfSprite_destroy(object->sprite);
    sfTexture_destroy(object->texture);
    free(object);
}

void update_frame_object(object_t *object)
{
    object->rect.left += object->rect.width;
    if (object->rect.left == object->rect.width * object->nb_frame)
        object->rect.left = 0;
    sfSprite_setTextureRect(object->sprite, object->rect);
}

void move_object(object_t *object, float x, float y)
{
    object->pos.x += x;
    object->pos.y += y;
    sfSprite_setPosition(object->sprite, object->pos);
}
