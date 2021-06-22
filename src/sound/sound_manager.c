/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** sound manager object
*/

#include "my_runner.h"
#include "sound_manager.h"

extern const char *SOUND_PATH[];
extern const float SOUND_VOLUME;
extern const float SOUND_VOLUME_MUSIC;

static void sound_manager_destroy(sound_manager_t *sm)
{
    for (int i = 0; i < SOUND_COUNT; i++) {
        sfMusic_destroy(sm->sounds[i]);
    }
}

static void sound_manager_play(sound_manager_t *sm, int id_sound)
{
    if (id_sound < 0 || id_sound >= SOUND_COUNT) {
        my_putstr_error("ERROR: sound_manager_play : invalid sound id.\n");
        return;
    }
    sfMusic_stop(sm->sounds[id_sound]);
    sfMusic_play(sm->sounds[id_sound]);
}

sound_manager_t *sound_manager_create(sound_manager_t *sm)
{
    sm->destroy = &sound_manager_destroy;
    sm->play = &sound_manager_play;
    for (int i = 0; i < SOUND_COUNT; i++) {
        sm->sounds[i] = sfMusic_createFromFile(SOUND_PATH[i]);
        if (!sm->sounds[i]) {
            my_putstr_error("ERROR: load sound\n");
            return NULL;
        }
        sfMusic_setVolume(sm->sounds[i], SOUND_VOLUME);
    }
    sfMusic_setVolume(sm->sounds[SOUND_THEME], SOUND_VOLUME_MUSIC);
    sfMusic_setLoop(sm->sounds[SOUND_THEME], sfTrue);
    sfMusic_setLoop(sm->sounds[SOUND_MENU], sfTrue);
    return sm;
}
