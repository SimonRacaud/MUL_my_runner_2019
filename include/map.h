/*
** EPITECH PROJECT, 2019
** csfml_2019
** File description:
** header
*/

#ifndef H_MAP
#define H_MAP

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>

#include "parallax.h"
#include "object.h"

typedef struct map {
    void (*destroy)(struct map *map);
    struct map *(*display)(window_t *w);
    char *buffer;
    char file_name;
    int width;
    int height;
    int block_size;
    int nb_type_block;
    object_t **type_block;
    object_t ***map;
    parallax_t parallax;
} map_t;

#endif
