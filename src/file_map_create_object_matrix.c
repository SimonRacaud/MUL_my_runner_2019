/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** Convert the character buffer (of the map) in object matrix
*/

#include "my_runner.h"

extern const int NB_TYPE_BLOCK;
extern const int NB_TYPE_CHAR;
extern const char *PATH_BLOCK_TEXTR;
extern const int BLOCK_TEXTR_SIZE;
extern const char MAP_BLOCK_CHAR[];

int load_type_block(map_t *map)
{
    sfVector2i size_block = {BLOCK_TEXTR_SIZE, BLOCK_TEXTR_SIZE};
    sfVector2f null_vec = {0, 0};

    map->type_block = malloc(sizeof(object_t *) * NB_TYPE_BLOCK);
    if (!map->type_block) {
        my_putstr_error("ERROR: malloc in load_type_block (file_map...c)\n");
        return EXIT_ERROR;
    }
    for (int i = 0; i < NB_TYPE_BLOCK; i++) {
        map->type_block[i] = object_create(PATH_BLOCK_TEXTR, &null_vec,
        &size_block, NB_TYPE_BLOCK);
        if (map->type_block[i] == NULL) {
            my_putstr_error("ERROR: object create in load_type_block\n");
            return EXIT_ERROR;
        }
        map->type_block[i]->set_frame(map->type_block[i], i);
    }
    return EXIT_SUCCESS;
}

static object_t *get_standard_block(char c, object_t **type_block)
{
    for (int i = 0; i < NB_TYPE_CHAR; i++) {
        if (c == MAP_BLOCK_CHAR[i] && i >= NB_TYPE_BLOCK)
            return NULL;
        else
            return type_block[i];
    }
    my_putstr_error("WARNING: invalid char int get_standard_block\n");
    return NULL;
}

static void set_standard_object_for_char(map_t *map)
{
    int x = 0;
    int y = 0;
    object_t *std_block;

    for (int idx = 0; map->buffer[idx] != '\0'; idx++) {
        if (map->buffer[idx] == '\n') {
            y = 0;
            x++;
        } else {
            std_block = get_standard_block(map->buffer[idx], map->type_block);
            map->map[x][y] = std_block;
            y++;
        }
    }
}

int load_map_from_buffer(map_t *map)
{
    if (!(map->map = malloc(sizeof(object_t **) * map->width))) {
        my_putstr_error("ERROR1: malloc in load_map_from_buffer\n");
        return EXIT_ERROR;
    }
    for (int x = 0; x < map->width; x++) {
        if (!(map->map[x] = malloc(sizeof(object_t *) * map->height))) {
            my_putstr_error("ERROR2: malloc in load_map_from_buffer\n");
            return EXIT_ERROR;
        }
    }
    set_standard_object_for_char(map);
    return EXIT_SUCCESS;
}
