/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** event manager : event functions
*/

#include "my_runner.h"
#include "event_manager.h"

extern const int W_WIDTH;
extern const int W_HEIGHT;
extern const int W_BPP;
extern const int FRAMERATE;
extern const char *TITLE_WINDOW;

void resize_window(window_t *w, sfEvent *event)
{
    w->width = (int)event->size.width;
    w->height = (int)event->size.height;
    w->resize_window = sfFalse;
    map_reload(w);
    w->game.player.obj->pos.y -= w->game.map.block_size * 2;
}

void event_end_game(window_t *w, int exit_status)
{
    w->exit_status = exit_status;
    w->show_menu = sfTrue;
    update_end_texts(w);
}

void event_space_menu(window_t *w)
{
    if (w->exit_status) {
        w->evt.close(w);
    } else {
        w->show_menu = sfFalse;
        sfMusic_setPlayingOffset(w->soundm.sounds[SOUND_THEME], (sfTime){0});
        sfClock_restart(w->game.clock);
        sfClock_restart(w->game.clock_score);
    }
}
