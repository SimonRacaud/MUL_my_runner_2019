/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** header
*/

#ifndef H_WINDOW
#define H_WINDOW

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>

#include "game.h"
#include "event_manager.h"
#include "sound_manager.h"
#include "menu.h"

typedef struct window {
    void (*destroy)(struct window *w);
    struct window *(*display)(struct window *w);
    sfRenderWindow *window;
    int width;
    int height;
    sfBool is_fullscreen;
    sfBool resize_window;
    sfBool show_menu;
    int exit_status;
    game_t game;
    event_manager_t evt;
    sound_manager_t soundm;
    menu_t menu;
} window_t;

#endif
