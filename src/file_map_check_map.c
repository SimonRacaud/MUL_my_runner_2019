/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** check the characters of the buffer and get height/width of the map.
*/

#include "my_runner.h"

extern const char MAP_BLOCK_CHAR[];
extern const int NB_TYPE_CHAR;

static int display_invalid_char(char *str)
{
    my_putstr_error("ERROR: invalid char : in check_map_buffer\n");
    str[1] = '\0';
    my_putstr_error("Invalid char: [");
    my_putstr_error(str);
    my_putstr_error("]\n");
    return EXIT_ERROR;
}

static void update_height_width(map_t *map, int *current_height)
{
    map->width++;
    if (*current_height > map->height)
        map->height = *current_height;
    *current_height = 0;
}

int check_map_buffer(map_t *map)
{
    int idx_block = 0;
    int idx_buffer = 0;
    int current_height = 0;

    while (map->buffer[idx_buffer] != '\0') {
        if (map->buffer[idx_buffer] == '\n') {
            update_height_width(map, &current_height);
            idx_buffer++;
            continue;
        }
        if (map->buffer[idx_buffer] == MAP_BLOCK_CHAR[idx_block]) {
            idx_block = 0;
            idx_buffer++;
            current_height++;
        } else if (idx_block == NB_TYPE_CHAR - 1) {
            return display_invalid_char(&map->buffer[idx_buffer]);
        } else
            idx_block++;
    }
    return EXIT_SUCCESS;
}
