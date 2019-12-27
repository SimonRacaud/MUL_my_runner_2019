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
    object_type_e (*get_typeblock)(struct map *map, window_t *w,
    sfVector2f *coord);
    char *buffer;
    char *file_name;
    int width;
    int height;
    int block_size;
    int nb_disp_cols;
    int nb_disp_rows;
    object_t **type_block;
    object_t ***map;
    parallax_t parallax;
} map_t;

int map_show_map(window_t *w);

int map_load_from_file(map_t *map);

int check_map_buffer(map_t *map);
int load_standard_block(map_t *map);
int load_map_from_buffer(map_t *map);

object_type_e map_get_typeblock(map_t *map, window_t *w, sfVector2f *coord);
sfVector2i map_get_block_coord(map_t *map, window_t *w, sfVector2f *coord);

#endif
