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
    if (w->exit_status == EXIT_RELOAD)
        return;
    w->show_menu = sfTrue;
    update_end_texts(w);
    if (w->exit_status == EXIT_FAIL)
        w->soundm.play(&w->soundm, SOUND_DIE);
    else if (w->exit_status == EXIT_WIN)
        w->soundm.play(&w->soundm, SOUND_WIN);
}

void event_space_menu(window_t *w)
{
    if (w->exit_status) {
        w->evt.close(w);
    } else {
        if (w->game.posx != 0) {
            event_pause_menu(w);
            return;
        }
        w->show_menu = sfFalse;
        sfMusic_setPlayingOffset(w->soundm.sounds[SOUND_THEME], (sfTime){0});
        sfClock_restart(w->game.clock);
        sfClock_restart(w->game.clock_score);
    }
}

void event_pause_menu(window_t *w)
{
    static float time_start_pause = 0;
    float now = GET_SECOND_CLOCK(w->game.clock);

    if (w->game.posx == 0 && w->show_menu)
        return;
    w->show_menu = !w->show_menu;
    if (w->show_menu)
        time_start_pause = now;
    else
        w->game.sub_time += (now - time_start_pause);
}
