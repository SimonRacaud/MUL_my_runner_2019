/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** object
*/

#include "my_runner.h"

static void object_display(object_t *object, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, object->sprite, NULL);
    sfSprite_setPosition(object->sprite, object->pos);
}

static void object_destroy(object_t *object)
{
    sfSprite_destroy(object->sprite);
    sfTexture_destroy(object->texture);
    free(object);
}

static void object_update_spite(object_t *object)
{
    object->rect.left += object->rect.width;
    if (object->rect.left == object->rect.width * object->nb_frame)
        object->rect.left = 0;
    sfSprite_setTextureRect(object->sprite, object->rect);
}

static void object_init(object_t *obj, int nb_frame)
{
    obj->destroy = &object_destroy;
    obj->display = &object_display;
    obj->update_sprite = &object_update_sprite;
    obj->move = &object_move;
    obj->set_speed = &object_set_speed;
    object->type = DEFAULT;
    object->speed = (sfVector2f){0.0f, 0.0f};
    object->nb_frame = nb_frame;
}

object_t *object_create(char *spritesheet_path, sfVector2f *pos,
sfVector2i *size, int nb_frame)
{
    object_t *object = malloc(sizeof(object_t));

    if (!object) {
        my_putstr_error("Error: create_duck\n");
        return NULL;
    }
    object->texture = sfTexture_createFromFile(spritesheet_path, NULL);
    object->sprite = sfSprite_create();
    if (!object->texture || !object->sprite) {
        my_putstr_error("Error: create_duck\n");
        free(object);
        return NULL;
    }
    object->rect = (sfIntRect){0, 0, size->x, size->y};
    object->pos = *pos;
    object_init(object, nb_frame);
    sfSprite_setTexture(object->sprite, object->texture, sfFalse);
    sfSprite_setTextureRect(object->sprite, object->rect);
    sfSprite_setPosition(object->sprite, *pos);
    return object;
}
