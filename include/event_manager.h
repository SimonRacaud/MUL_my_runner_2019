/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** header
*/

#ifndef H_EVENT
#define H_EVENT

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>

#include "window.h"

typedef struct event_manager {
    void (*exec)(window_t *w, sfEvent *event);
    void (*mouse_click)(window_t *w, sfEvent *event);
    void (*mouse_move)(window_t *w, sfEvent *event);
    void (*key_release)(window_t *w, sfEvent *event);
    void (*resize)(window_t *w, sfEvent *event);
    void (*close)(window_t *w);
    void (*end_game)(window_t *w, int exit_status);
} event_manager_t;

void resize_window(window_t *w, sfEvent *event);
void event_end_game(window_t *w, int exit_status);

#endif
