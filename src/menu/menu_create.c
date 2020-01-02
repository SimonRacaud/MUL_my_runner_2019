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

static int create_end_texts(window_t *w)
{
    w->menu.exit_status_msg = sfText_copy(w->menu.title);
    sfText_setPosition(w->menu.exit_status_msg, MENU_STATUSMSG_POS);
    sfText_setColor(w->menu.exit_status_msg, sfMagenta);
    sfText_setCharacterSize(w->menu.exit_status_msg, MENU_ENDMSG_SIZE);
    w->menu.score_msg = sfText_copy(w->menu.exit_status_msg);
    w->menu.coin_msg = sfText_copy(w->menu.exit_status_msg);
    if (!w->menu.exit_status_msg || !w->menu.score_msg || !w->menu.coin_msg)
        return EXIT_ERROR;
    sfText_setPosition(w->menu.score_msg, MENU_SCOREMSG_POS);
    sfText_setPosition(w->menu.coin_msg, MENU_COINMSG_POS);
    return EXIT_SUCCESS;
}

static int create_texts(window_t *w)
{
    w->menu.title = sfText_create();
    if (!w->menu.title)
        return EXIT_ERROR;
    sfText_setColor(w->menu.title, sfRed);
    sfText_setFont(w->menu.title, w->game.font);
    w->menu.subtitle = sfText_copy(w->menu.title);
    w->menu.input_msg = sfText_copy(w->menu.title);
    if (!w->menu.subtitle || !w->menu.input_msg)
        return EXIT_ERROR;
    sfText_move(w->menu.title, MENU_TITLE_POS);
    sfText_setString(w->menu.title, MENU_TITLE);
    sfText_setCharacterSize(w->menu.title, MENU_TITLE_SIZE);
    sfText_move(w->menu.subtitle, MENU_SUBTITLE_POS);
    sfText_setString(w->menu.subtitle, MENU_SUBTITLE);
    sfText_setCharacterSize(w->menu.subtitle, MENU_SUBTITLE_SIZE);
    sfText_move(w->menu.input_msg, MENU_INPUTMSG_POS);
    sfText_setString(w->menu.input_msg, MENU_INPUTMSG);
    sfText_setCharacterSize(w->menu.input_msg, MENU_INPUTMSG_SIZE);
    return EXIT_SUCCESS;
}

menu_t *menu_create(window_t *w)
{
    w->menu.destroy = &menu_destroy;
    w->menu.display = &menu_display;
    w->menu.parallax = &w->game.map.parallax;
    if (create_texts(w) == EXIT_ERROR)
        return NULL;
    else if (create_end_texts(w) == EXIT_ERROR)
        return NULL;
    return (&w->menu);
}
