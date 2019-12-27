/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** contants
*/

#include <SFML/Graphics.h>

const char *PATH_DUCKSHEET = "asset/sprite/duck_spritesheet.png";

const char *PATH_FONT = "asset/font/BebasNeue-Regular.ttf";
const double SPEEDX = 150.0f;

const int PARALLAX_T_SX = 1920;
const int PARALLAX_T_SY = 1080;
const char *PATH_SETT_BG = "asset/sprite/setting01.png";
const char *PATH_SETT_FG = "asset/sprite/setting02.png";
const char *PATH_CLOUD = "asset/sprite/clouds.png";
const char *PATH_BG = "asset/sprite/background.png";

const int BLOCK_SIZE = 40;
const int NB_TYPE_CHAR = 9;
const int NB_TYPE_BLOCK = 7;
const char *PATH_BLOCK_TEXTR = "asset/sprite/block_basic.png";
const int BLOCK_TEXTR_SIZE = 100;
const char MAP_BLOCK_CHAR[] =
{
    '#',
    '=',
    '|',
    ' ',
    '.',
    '*',
    '@',
    'E',
    '\n'
};

const char *PATH_PLAYER_SSHEET = "asset/sprite/player.png";
const sfVector2i PLAYER_SPRITE_SIZE = (sfVector2i){200, 400};
const int PLAYER_HEIGHT = BLOCK_SIZE * 2;
const float PLAYER_POSX = 300.0f;
const double PLAYER_FPMS = 100;
const int CODE_HIT_BLOCK = 1;
const int CODE_NO_HIT_BLOCK = 2;
const int CODE_COIN_BLOCK = 2;

const int CHAR_SIZE = 0;

const int W_WIDTH = 1920;
const int W_HEIGHT = 1080;
const int W_BPP = 32;
const int FRAMERATE = 30;
const char *TITLE_WINDOW = "My Runner 2019 - RACAUD Simon";
