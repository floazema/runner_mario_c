/*
** EPITECH PROJECT, 2021
** mystruct
** File description:
** struct init
*/

#ifndef __MY_STRUCT__
    #define __MY_STRUCT__

typedef struct windowandbackground {
    sfRenderWindow *SuperMarioMaker;
    sfSprite *start, *end, *gameback;
    sfSprite *cloud, *cloud2, *win;
    sfTexture *my_win, *my_end, *my_midback;
    sfSprite *midback;
    sfSprite *midback2;
    sfTexture *my_midback2;
    sfTexture *my_start;
    sfTexture *my_cloud;
    sfTexture *my_cloud2;
    sfSprite *backback;
    sfSprite *backback2;
    sfTexture *my_backback;
    sfTexture *my_backback2;
    sfTexture *my_gameback;
    sfMusic *musicf;
    int j, y, y2, x;
    int x2, z, z2;
} back_t;

typedef struct mario {
    int airtime;
    int isjump;
    int isfall;
    int carac;
    int intscore;
    int velocity;
    float height;
    float mario_sec;
    sfIntRect mariorect;
    sfSprite *sprite_mario;
    sfTexture *my_mario_sprite;
    sfMusic *jumpsound;
} mario_t;

typedef struct myclocks {
    float jumpsec;
    float cloudsec;
    float mapsec;
    float gravitysec;
    sfClock *gravity_clock;
    sfTime gravity_time;
    float gravitytime;
    sfClock *mario_clock;
    sfTime mario_time;
    sfClock *jump_clock;
    sfTime jump_time;
    sfClock *cloud_clock;
    sfClock *parralaxmap;
    sfTime parralaxmaptime;
    sfTime cloud_time;
} clocks_t;

typedef struct mapelement {
    char *map;
    char **doublemap;
    int linelength;
    int parralax;
    sfVector2f objct_pos;
    sfSprite *grass;
    sfTexture *my_grass;
    sfSprite *ground;
    sfTexture *my_block;
    sfSprite *block;
    sfTexture *my_ground;
    sfSprite *goomba;
    sfTexture *my_flag;
    sfSprite *flag;
    sfTexture *my_goomba;
} mapelement_t;

#endif/*__MY_STRUCT__*/
