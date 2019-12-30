/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** contants
*/

#include <SFML/Graphics.h>

const char *PATH_DUCKSHEET = "asset/sprite/duck_spritesheet.png";

const char *PATH_FONT = "asset/font/BebasNeue-Regular.ttf";
const double SPEEDX = 200.0f;

const int PARALLAX_T_SX = 1920;
const int PARALLAX_T_SY = 1080;
const char *PATH_SETT_BG = "asset/sprite/setting01.png";
const char *PATH_SETT_FG = "asset/sprite/setting02.png";
const char *PATH_CLOUD = "asset/sprite/clouds.png";
const char *PATH_BG = "asset/sprite/background.png";

const int ENEMY_NB_SPR = 4;
const int ENEMY_FPMS = 100;
const int ENEMY_TXR_SIZE = 200;
const char *PATH_ENEMY_SHEET = "asset/sprite/enemy_idle.png";
const int BLOCK_SIZE = 60;
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

const int CODE_HIT_BLOCK = 1;
const int CODE_NO_HIT_BLOCK = 2;
const int CODE_COIN_BLOCK = 3;
const int CODE_TRAP = 4;
const char *PATH_PLAY_SHEET = "asset/sprite/player.png";
const sfVector2i PLAYER_SPRITE_SIZE = {200, 400};
const int P_NB_SPR = 3;
const int PLAYER_HEIGHT = BLOCK_SIZE * 2;
const float PLAYER_POSX = 240.0f;
const double PLAYER_FPMS = 100;
const float PLAYER_JUMP_VELOCITY = -BLOCK_SIZE / 2.8;
const float PLAYER_MAX_VELOCITY = -PLAYER_JUMP_VELOCITY / 1.2;
const float PLAYER_JUMP_GRAVITY = 0.9f;

const int W_WIDTH = 1920;
const int W_HEIGHT = 1080;
const int W_BPP = 32;
const int FRAMERATE = 30;
const char *TITLE_WINDOW = "My Runner 2019 - RACAUD Simon";

const sfVector2f TXT_SCORE_POS = {50, 10};
const sfVector2f TXT_COIN_POS = {50, 70};
const int PANEL_CHAR_SIZE = 40;

const float SOUND_VOLUME = 80;
const float SOUND_VOLUME_MUSIC = 50;

#define SOUND_COUNT_1 6

const char *SOUND_PATH[SOUND_COUNT_1] =
{
    "./asset/sound/maintheme.ogg",
    "./asset/sound/maintheme.ogg",
    "./asset/sound/jump.ogg",
    "./asset/sound/dead.ogg",
    "./asset/sound/coin.ogg",
    "./asset/sound/win.ogg"
};
