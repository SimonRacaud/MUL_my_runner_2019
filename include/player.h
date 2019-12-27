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
    int (*check_collision)(struct player *player, map_t *map, window_t *w);
    void (*jump)(struct player *player);
    object_t *obj;
    sfVector2f velocity;
} player_t;

int player_check_collision(player_t *player, map_t *map, window_t *w);

player_t *player_set_velocity(player_t *player, float x, float y);
float player_get_posy(map_t *map, window_t *w);

int get_hitcode(map_t *map, window_t *w, sfVector2f *point);
int player_check_hit_front(map_t *map, player_t *player, window_t *w);
int player_check_hit_bottom(map_t *map, player_t *player, window_t *w);
int player_check_hit_top(map_t *map, player_t *player, window_t *w);

#endif
