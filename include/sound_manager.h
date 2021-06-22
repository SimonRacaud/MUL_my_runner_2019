/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** header
*/

#ifndef H_SOUND
#define H_SOUND

#include <SFML/Audio.h>

#define SOUND_COUNT 6

#define SOUND_THEME 0
#define SOUND_MENU 1
#define SOUND_JUMP 2
#define SOUND_DIE 3
#define SOUND_COIN 4
#define SOUND_WIN 5

typedef struct sound_manager {
    void (*destroy)(struct sound_manager *sm);
    void (*play)(struct sound_manager *sm, int id_sound);
    sfMusic *sounds[SOUND_COUNT];
} sound_manager_t;

#endif
