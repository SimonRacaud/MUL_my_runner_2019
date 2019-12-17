/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** Convert the character buffer (of the map) in object matrix
*/

#include "my_runner.h"

extern const int NB_TYPE_BLOCK;
extern const char *PATH_BLOCK_TEXTR;
extern const int BLOCK_TEXTR_SIZE;

int load_type_block(map_t *map)
{
    sfVector2f size_block = {BLOCK_TEXTR_SIZE, BLOCK_TEXTR_SIZE};
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

int load_map_from_buffer(map_t *map)
{
    return EXIT_SUCCESS;
}
