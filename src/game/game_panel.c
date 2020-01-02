/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** game : show the game panel (player score, coin counter)
*/

#include "my_runner.h"

extern const sfVector2f TXT_SCORE_POS;
extern const sfVector2f TXT_COIN_POS;
extern const int PANEL_CHAR_SIZE;

int game_create_panel(game_t *game)
{
    game->score = sfText_create();
    game->coins = sfText_create();
    if (!game->score || !game->coins)
        return EXIT_ERROR;
    sfText_move(game->score, TXT_SCORE_POS);
    sfText_move(game->coins, TXT_COIN_POS);
    sfText_setColor(game->score, sfBlue);
    sfText_setColor(game->coins, sfBlue);
    sfText_setFont(game->score, game->font);
    sfText_setFont(game->coins, game->font);
    my_strcpy(game->txt_score, "Score: 0");
    my_strcpy(game->txt_coins, "Coin: 0");
    sfText_setString(game->score, game->txt_score);
    sfText_setString(game->coins, game->txt_coins);
    sfText_setCharacterSize(game->score, PANEL_CHAR_SIZE);
    sfText_setCharacterSize(game->coins, PANEL_CHAR_SIZE);
    return EXIT_SUCCESS;
}

void game_destroy_panel(game_t *game)
{
    sfText_destroy(game->score);
    sfText_destroy(game->coins);
}

void game_update_panel(window_t *w)
{
    sfInt32 score = GET_MSECOND_CLOCK(w->game.clock_score) / 100;
    char *new_score = my_putnbr_base_str((int)score, "0123456789");
    char *new_coins = my_putnbr_base_str(w->game.coin_counter, "0123456789");

    my_strncpy((w->game.txt_score + 7), new_score, 5);
    my_strncpy((w->game.txt_coins + 6), new_coins, 5);
    free(new_score);
    free(new_coins);
    sfText_setString(w->game.score, w->game.txt_score);
    if (w->game.coin_counter != 0)
        sfText_setString(w->game.coins, w->game.txt_coins);
}

void game_show_panel(window_t *w)
{
    sfRenderWindow_drawText(w->window, w->game.score, NULL);
    sfRenderWindow_drawText(w->window, w->game.coins, NULL);
}
