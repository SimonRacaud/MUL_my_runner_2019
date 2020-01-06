/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** Load standard blocks
*/

#include "my_runner.h"

extern const int NB_TYPE_BLOCK;
extern const char *PATH_BLOCK_TEXTR;
extern const int BLOCK_TEXTR_SIZE;
extern const char *PATH_ENEMY_SHEET;
extern const int ENEMY_NB_SPR;
extern const int ENEMY_TXR_SIZE;
extern const int ENEMY_FPMS;

static void set_standardblock_type(object_t *block, int id_type)
{
    if (id_type < NB_TYPE_BLOCK)
        block->type = id_type + 4;
    else if (id_type == NB_TYPE_BLOCK)
        block->type = ENEMY;
    else
        block->type = DEFAULT;
}

static int create_standard_block(map_t *map)
{
    sfVector2i size_block = {BLOCK_TEXTR_SIZE, BLOCK_TEXTR_SIZE};
    sfVector2f null_vec = {0, 0};
    float block_scale = (float)map->block_size / BLOCK_TEXTR_SIZE;
    sfVector2f scale = {block_scale, block_scale};

    for (int i = 0; i < NB_TYPE_BLOCK; i++) {
        map->type_block[i] = object_create(PATH_BLOCK_TEXTR, &null_vec,
        &size_block, NB_TYPE_BLOCK);
        if (map->type_block[i] == NULL) {
            my_putstr_error("ERROR: object create in load_type_block\n");
            return EXIT_ERROR;
        }
        sfSprite_setScale(map->type_block[i]->sprite, scale);
        map->type_block[i]->set_frame(map->type_block[i], i);
        set_standardblock_type(map->type_block[i], i);
    }
    return EXIT_SUCCESS;
}

static int create_enemy_block(map_t *map)
{
    sfVector2i size_block = {ENEMY_TXR_SIZE, ENEMY_TXR_SIZE};
    sfVector2f null_vec = {0, 0};
    float block_scale = (float)map->block_size / ENEMY_TXR_SIZE;
    sfVector2f scale = {block_scale, block_scale};

    map->type_block[NB_TYPE_BLOCK] = object_create(PATH_ENEMY_SHEET, &null_vec,
    &size_block, ENEMY_NB_SPR);
    if (map->type_block[NB_TYPE_BLOCK] == NULL) {
        my_putstr_error("ERROR: object create in load_type_block\n");
        return EXIT_ERROR;
    }
    sfSprite_setScale(map->type_block[NB_TYPE_BLOCK]->sprite, scale);
    map->type_block[NB_TYPE_BLOCK]->type = ENEMY;
    SET_FPS(map->type_block[NB_TYPE_BLOCK], ENEMY_FPMS);
    return EXIT_SUCCESS;
}

int load_standard_block(map_t *map)
{
    int nb_standard_block = NB_TYPE_BLOCK + 1;

    if (!(map->type_block = malloc(sizeof(object_t *) * nb_standard_block))) {
        my_putstr_error("ERROR: malloc in load_type_block (file_map...c)\n");
        return EXIT_ERROR;
    }
    if (create_standard_block(map) == EXIT_ERROR)
        return EXIT_ERROR;
    else if (create_enemy_block(map) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
