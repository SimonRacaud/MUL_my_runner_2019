/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** menu class
*/

#include "my_runner.h"
#include "menu.h"

extern const char *MENU_TITLE;
extern const int MENU_TITLE_SIZE;
extern const sfVector2f MENU_TITLE_POS;
extern const char *MENU_SUBTITLE;
extern const int MENU_SUBTITLE_SIZE;
extern const sfVector2f MENU_SUBTITLE_POS;
extern const char *MENU_INPUTMSG;
extern const int MENU_INPUTMSG_SIZE;
extern const sfVector2f MENU_INPUTMSG_POS;
extern const int MENU_ENDMSG_SIZE;
extern const sfVector2f MENU_STATUSMSG_POS;
extern const sfVector2f MENU_SCOREMSG_POS;
extern const sfVector2f MENU_COINMSG_POS;

void menu_destroy(menu_t *menu)
{
    sfText_destroy(menu->title);
    sfText_destroy(menu->subtitle);
    sfText_destroy(menu->input_msg);
    sfText_destroy(menu->score_msg);
    sfText_destroy(menu->exit_status_msg);
    sfText_destroy(menu->coin_msg);
}

menu_t *menu_display(window_t *w)
{
    w->menu.parallax->display(w->menu.parallax, w->window);
    sfRenderWindow_drawText(w->window, w->menu.title, NULL);
    sfRenderWindow_drawText(w->window, w->menu.subtitle, NULL);
    sfRenderWindow_drawText(w->window, w->menu.input_msg, NULL);
    if (w->exit_status) {
        sfRenderWindow_drawText(w->window, w->menu.exit_status_msg, NULL);
        sfRenderWindow_drawText(w->window, w->menu.score_msg, NULL);
        sfRenderWindow_drawText(w->window, w->menu.coin_msg, NULL);
    }
    return &(w->menu);
}

int update_end_texts(window_t *w)
{
    if (w->exit_status == EXIT_WIN)
        sfText_setString(w->menu.exit_status_msg, "VICTORY");
    else if (w->exit_status == EXIT_FAIL)
        sfText_setString(w->menu.exit_status_msg, "DEFEAT");
    sfText_setString(w->menu.score_msg, w->game.txt_score);
    sfText_setString(w->menu.coin_msg, w->game.txt_coins);
    return EXIT_SUCCESS;
}
