/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** main
*/

#include "my_runner.h"

extern const char *USAGE_MESSAGE;

static void usage_game_explain(void)
{
    my_putchar('\n');
    my_putstr("|---------------------------------------------------------\n");
    my_putstr("| This game is a runner/platformer game.\n|\n");
    my_putstr("| The player loose if he touches an enemy(obstacle), if");
    my_putstr(" he hits a map block (in the front)\n|  or if he falls in a");
    my_putstr(" hole.\n|\n");
    my_putstr("| The player can gets bonus/malus coins by hitting them.\n");
    my_putstr("| (The bonus coins add a bonus score and \n| the malus ");
    my_putstr("coins remove a part of the bonus score collected)\n");
    my_putstr("|---------------------------------------------------------\n");
}

static int usage(int status)
{
    my_putstr("\033[1m\033[34m");
    my_putstr("Finite runner created with CSFML.\n\n");
    my_putstr("USAGE\n\t./my_runner maps/map_name.map\n\nOPTIONS\n");
    my_putstr("\t-i\tLaunch the game in infinity mode.\n");
    my_putstr("\t-h\tPrint the usage and quit.\n");
    my_putstr("\t-p [0-3] Customize the character.\n");
    my_putstr("\t\t[0] Marvin,\n\t\t[1] Nazi mode,\n\t\t[2] Cetelem mode,");
    my_putstr("\n\t\t[3] Pinky mode\n");
    my_putstr("\nUSER INTERACTIONS\n");
    my_putstr("\tSPACE_KEY\tJump.\n");
    my_putstr("\tESCAPE_KEY\tExit game.\n");
    my_putstr("\t[F]\t\tChange fullscreen mode. (enable/disable)\n");
    my_putstr("\t[P]\t\tPause the game. (enable/disable)\n");
    usage_game_explain();
    my_putstr("\033[0m");
    return status;
}

static int get_options(sfBool *infinite_mode, char **character_sprite,
int argc, char **argv)
{
    int idx_map = -1;
    int idx_char_sprite = 0;

    for (int i = 1; i < argc; i++) {
        if (!my_strcmp("-i", argv[i])) {
            *infinite_mode = sfTrue;
        } else if (!my_strcmp("-p", argv[i]) && (i + 1) < argc) {
            *character_sprite = argv[i + 1];
            idx_char_sprite = (i + 1);
        }
        if (argv[i][0] != '-' && idx_map == -1 && i != idx_char_sprite) {
            idx_map = i;
        }
    }
    return idx_map;
}

int main(int argc, char **argv)
{
    sfBool infinite_mode = sfFalse;
    char *character_sprite = "0";
    int idx_map;

    if (argc > 1 && !my_strcmp(argv[1], "-h")) {
        return usage(EXIT_SUCCESS);
    }
    my_printf("\033[34m%s\033[0m", USAGE_MESSAGE);
    if (argc > 1) {
        idx_map = get_options(&infinite_mode, &character_sprite, argc, argv);
        if (idx_map == -1)
            return usage(EXIT_ERROR);
        return run(argv[idx_map], infinite_mode, character_sprite);
    }
    return usage(EXIT_SUCCESS);
}
