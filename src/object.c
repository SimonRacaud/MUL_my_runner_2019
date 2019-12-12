/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** object
*/

#include "my_runner.h"

static object_t *object_display(object_t *object, sfRenderWindow *window,
sfClock *clock)
{
    if (object->nb_frame != 0)
        object->update_sprite(object, clock);
    if (object->speed.x != 0 || object->speed.y != 0)
        object->move(object, clock);
    sfRenderWindow_drawSprite(window, object->sprite, NULL);
    return object;
}

static void object_destroy(object_t *object)
{
    sfSprite_destroy(object->sprite);
    sfTexture_destroy(object->texture);
    free(object);
}

static object_t *object_update_spite(object_t *object, sfClock *clock)
{
    int nb_frame = 0;

    if (object->frame_per_ms == 0)
        return object;
    object->timer_frame += sfClock_getElapsedTime(clock).microseconds;
    if (object->timer_frame >= (object->frame_per_ms * 1000)) {
        nb_frame = object->timer_frame / (object->frame_per_ms * 1000);
        object->timer_frame -= (nb_frame * (object->frame_per_ms * 1000));
        for (int i = 0; i < nb_frame; i++)
            object_set_next_frame(object);
        sfSprite_setTextureRect(object->sprite, object->rect);
    }
    return object;
}

static void object_init(object_t *obj, int nb_frame)
{
    obj->destroy = &object_destroy;
    obj->display = &object_display;
    obj->update_sprite = &object_update_spite;
    obj->move = &object_move;
    obj->set_speed = &object_set_speed;
    obj->set_fps = &object_set_fps;
    obj->set_mps = &object_set_mps;
    obj->type = DEFAULT;
    obj->speed = (sfVector2f){0.0f, 0.0f};
    obj->nb_frame = nb_frame;
    obj->timer_frame = 0;
    obj->timer_position = 0;
    obj->frame_per_ms = 0;
    obj->mov_per_ms = 0;
}

object_t *object_create(const char *spritesheet_path, sfVector2f *pos,
sfVector2i *size, int nb_frame)
{
    object_t *object = malloc(sizeof(object_t));

    if (!object) {
        my_putstr_error("Error: create object\n");
        return NULL;
    }
    object->texture = sfTexture_createFromFile(spritesheet_path, NULL);
    object->sprite = sfSprite_create();
    if (!object->texture || !object->sprite) {
        my_putstr_error("Error: create object\n");
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
