/*
** EPITECH PROJECT, 2019
** my_runner_2019
** File description:
** contants
*/

#include <SFML/Graphics.h>

const char *USAGE_MESSAGE = "[Information] : Usages can be displayed \
with the -h option.\n\n";

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
const int NB_TYPE_CHAR = 10;
const int NB_TYPE_BLOCK = 8;
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
    '8',
    'E',
    '\n'
};
const int CODE_HIT_BLOCK = 1;
const int CODE_NO_HIT_BLOCK = 2;
const int CODE_COIN_BLOCK = 3;
const int CODE_TRAP = 4;
const int CODE_MALUS_BLOCK = 5;

const int NB_PLAYER_SHEET = 4;
const char *PATH_PLAY_SHEET[4] =
{
    "asset/sprite/player0.png",
    "asset/sprite/player1.png",
    "asset/sprite/player2.png",
    "asset/sprite/player3.png"
};
const char *PLAYER_OPTION_SPRITE[4] =
{
    "0",
    "1",
    "2",
    "3"
};
const sfVector2i PLAYER_SPRITE_SIZE = {200, 400};
const int P_NB_SPR = 3;
const int PLAYER_HEIGHT = BLOCK_SIZE * 2;
const float PLAYER_POSX = 240.0f;
const double PLAYER_FPMS = 100;
const float PLAYER_JUMP_VELOCITY = -BLOCK_SIZE / 2.6;
const float PLAYER_MAX_VELOCITY = -PLAYER_JUMP_VELOCITY / 1.4;
const float PLAYER_JUMP_GRAVITY = 1.1f;

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

const char *SOUND_PATH[] =
{
    "./asset/sound/maintheme.ogg",
    "./asset/sound/maintheme.ogg",
    "./asset/sound/jump.ogg",
    "./asset/sound/dead.ogg",
    "./asset/sound/coin.ogg",
    "./asset/sound/win.ogg"
};

const char *MENU_TITLE = "My RUNNER 2019";
const int MENU_TITLE_SIZE = 100;
const sfVector2f MENU_TITLE_POS = {W_WIDTH / 2 - 250, W_HEIGHT * 0.2};
const char *MENU_SUBTITLE = "Epitech - RACAUD Simon";
const int MENU_SUBTITLE_SIZE = 30;
const sfVector2f MENU_SUBTITLE_POS = {W_WIDTH / 2 - 250, W_HEIGHT * 0.3};
const char *MENU_INPUTMSG = "Press [SPACE] to continue";
const int MENU_INPUTMSG_SIZE = 30;
const sfVector2f MENU_INPUTMSG_POS = {W_WIDTH / 2 - 150, W_HEIGHT * 0.9};
const int MENU_ENDMSG_SIZE = 30;
const sfVector2f MENU_STATUSMSG_POS = {W_WIDTH / 2 - 100, W_HEIGHT * 0.44};
const sfVector2f MENU_SCOREMSG_POS = {W_WIDTH / 2 - 100, W_HEIGHT * 0.5};
const sfVector2f MENU_COINMSG_POS = {W_WIDTH / 2 - 100, W_HEIGHT * 0.55};
