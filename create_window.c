/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** create window
*/

#include "my_runner.h"

window_t *create_window(void)
{
    window_t *w = malloc(sizeof(window_t));
    sfVideoMode mode = {W_WIDTH, W_HEIGHT, 32};

    w->window = sfRenderWindow_create(mode, "my runner", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(w->window, framerate_g);
    w->timer = sfClock_create();
    char *setting[2] = {"asset/setting01.png", "asset/setting02.png"};
    create_parallax("asset/background.png", "asset/clouds.png", setting, w);

    sfVector2f pos_duck = {200, 200};
    sfVector2i size_duck = {110, 110};
    w->duck = create_object("duck_spritesheet.png", &pos_duck, &size_duck, 3);
    object_set_speed(w->duck, 10, 10);
    //sfRenderWindow_setMouseCursorVisible(w->window, sfFalse);
    //w->font = sfFont_createFromFile(PATH_FONT);
    if (!w->window /*|| !w->font*/)
        return NULL;
    return w;
}

void destroy_window(window_t *w)
{
    sfRenderWindow_destroy(w->window);
    sfClock_destroy(w->timer);
    destroy_object(w->duck);
    destroy_parallax(&w->parallax);
    //sfFont_destroy(w->font);
    free(w);
}
