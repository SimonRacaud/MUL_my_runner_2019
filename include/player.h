/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** header
*/

#ifndef H_PLAYER
#define H_PLAYER

typedef struct player {
    void (*destroy)(struct player *player);
    struct player *(*display)(window_t *w);
    struct player *(*set_velocity)(struct player *player, float x, float y);
    int (*check_collision)(struct player *player, map_t *map);
    object_t *obj;
    sfVector2f velocity;
} player_t;

player_t *player_set_velocity(player_t *player, float x, float y);
float player_get_posy(map_t *map, window_t *w);


#endif
