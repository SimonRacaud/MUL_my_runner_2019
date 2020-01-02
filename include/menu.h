/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** header
*/

#ifndef H_MENU
#define H_MENU

#include <SFML/Graphics.h>

typedef struct menu {
    void (*destroy)(struct menu *menu);
    struct menu *(*display)(struct window *w);
    parallax_t *parallax;
    sfText *title;
    sfText *subtitle;
    sfText *exit_status_msg;
    sfText *score_msg;
    sfText *coin_msg;
    sfText *input_msg;
} menu_t;

void menu_destroy(menu_t *menu);
menu_t *menu_display(window_t *w);
menu_t *menu_create(window_t *w);
int update_end_texts(window_t *w);

#endif
