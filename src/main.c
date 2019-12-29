/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** main
*/

#include "my_runner.h"

int usage(int status)
{
    my_putstr("Finite runner created with CSFML.\n\n");
    my_putstr("USAGE\n\t./my_runner map.txt\n\nOPTIONS\n");
    my_putstr("\t-i\tlaunch the game in infinity mode.\n");
    my_putstr("\t-h\tprint the usage and quit.\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("\tSPACE_KEY\tjump.\n");
    my_putstr("\tESCAPE_KEY\tExit game.\n");
    my_putstr("\t[F]\tChange fullscreen mode.\n");
    return status;
}

int main(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h"))
        return run(argv[1]);
    return usage(EXIT_SUCCESS);
}
