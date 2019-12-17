/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** load map form file
*/

#include "my_runner.h"

static int load_file(map_t *map)
{
    int fd = open(map->file_name, O_RDONLY);
    stat_t stat_of_file;
    int ret = stat(map->file_name, &stat_of_file);

    if (fd == -1 || ret != 0) {
        my_putstr_error("ERROR: open file : in load_file (file_map.c)\n");
        return EXIT_ERROR;
    }
    if (!(map->buffer = malloc(sizeof(char) * (stat_of_file.st_size + 1)))) {
        my_putstr_error("ERROR: malloc : in load_file (file_map.c)\n");
        return EXIT_ERROR;
    }
    ret = read(fd, map->buffer, (stat_of_file.st_size + 1));
    close(fd);
    if (ret == -1) {
        my_putstr_error("ERROR: read map file : in load_file (file_map.c)\n");
        return EXIT_ERROR;
    }
    map->buffer[stat_of_file.st_size] = '\0';
    return EXIT_SUCCESS;
}

int map_load_from_file(map_t *map)
{
    if (load_file(map) == EXIT_ERROR) {
        return EXIT_ERROR;
    } else if (check_map_buffer(map) == EXIT_ERROR) {
        free(map->buffer);
        return EXIT_ERROR;
    }
    if (load_type_block(map) == EXIT_ERROR) {
        free(map->buffer);
        return EXIT_ERROR;
    } else if (load_map_from_buffer(map) == EXIT_ERROR) {
        free(map->buffer);
        for (int i = 0; i < NB_TYPE_BLOCK; i++)
            map->type_block[i]->destroy(map->type_block[i]);
        free(map->type_block);
    }
    return EXIT_SUCCESS;
}
