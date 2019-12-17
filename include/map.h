/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** header
*/

#ifndef H_MAP
#define H_MAP

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "parallax.h"
#include "object.h"

typedef struct stat stat_t;

typedef struct map {
    void (*destroy)(struct map *map);
    struct map *(*display)(window_t *w);
    char *buffer;
    char *file_name;
    int width;
    int height;
    int block_size;
    object_t **type_block;
    object_t ***map;
    parallax_t parallax;
} map_t;

int map_load_from_file(map_t *map);
int check_map_buffer(map_t *map);

#endif
