/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner
*/

#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <struct.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void others(back_t *back)
{
    back->my_cloud2 = sfTexture_createFromFile("assets/nuages2.png", NULL);
    back->my_midback = sfTexture_createFromFile("assets/backmid.png", NULL);
    back->my_midback2 = sfTexture_createFromFile("assets/backmid2.png", NULL);
    back->my_backback = sfTexture_createFromFile("assets/back.png", NULL);
    back->my_backback2 = sfTexture_createFromFile("assets/back2.png", NULL);
    back->z = 0;
    back->z2 = 1920;
    back->backback = sfSprite_create();
    back->backback2 = sfSprite_create();
    back->cloud2 = sfSprite_create();
    back->midback = sfSprite_create();
    back->midback2 = sfSprite_create();
    sfSprite_setTexture(back->cloud2, back->my_cloud2, sfTrue);
    sfSprite_setTexture(back->backback, back->my_backback, sfTrue);
    sfSprite_setTexture(back->backback2, back->my_backback2, sfTrue);
    sfSprite_setTexture(back->midback, back->my_midback, sfTrue);
    sfSprite_setTexture(back->midback2, back->my_midback2, sfTrue);
    back->x2 = 1920;
    back->y = 0;
    back->y2 = 1920;
}

void spritecreate(back_t *back)
{
    back->my_start = sfTexture_createFromFile("assets/startback.png", NULL);
    back->start = sfSprite_create();
    back->my_end = sfTexture_createFromFile("assets/endgame.png", NULL);
    back->end = sfSprite_create();
    back->my_win = sfTexture_createFromFile("assets/levelclear.png", NULL);
    back->win = sfSprite_create();
    back->my_cloud = sfTexture_createFromFile("assets/nuages.png", NULL);
    back->cloud = sfSprite_create();
}

back_t my_init(void)
{
    back_t back;
    sfVideoMode mode = {1920, 1080, 32};

    spritecreate(&back);
    back.SuperMarioMaker = sfRenderWindow_create\
    (mode, "SuperMarioMaker", sfClose, NULL);
    back.j = 0, back.x = 0;
    sfRenderWindow_setFramerateLimit(back.SuperMarioMaker, 60);
    sfSprite_setTexture(back.win, back.my_win, sfTrue);
    sfSprite_setTexture(back.start, back.my_start, sfTrue);
    sfSprite_setTexture(back.end, back.my_end, sfTrue);
    sfSprite_setTexture(back.cloud, back.my_cloud, sfTrue);
    back.musicf = sfMusic_createFromFile("assets/mario music.ogg");
    sfMusic_setLoop(back.musicf, sfTrue);
    sfMusic_play(back.musicf);
    others(&back);
    return back;
}

mario_t mario_init(void)
{
    mario_t mario;
    mario.height = 0;
    sfVector2f posmario = {256, mario.height};

    mario.my_mario_sprite = sfTexture_createFromFile\
    ("assets/marioluigi.png", NULL);
    mario.sprite_mario = sfSprite_create();
    sfSprite_setTexture(mario.sprite_mario, mario.my_mario_sprite, sfTrue);
    mario.jumpsound = sfMusic_createFromFile("assets/saut.ogg");
    mario.mariorect.top = 0;
    mario.mariorect.left = 0;
    mario.mariorect.width = 88;
    mario.mariorect.height = 180;
    mario.mario_sec = 0;
    mario.airtime = 0;
    mario.isjump = 0;
    mario.intscore = 0;
    mario.isfall = 0;
    sfSprite_setPosition(mario.sprite_mario, posmario);
    return mario;
}

clocks_t clocks_init(void)
{
    clocks_t clocks;
    clocks.mapsec = 0;
    clocks.gravitysec = 0;
    clocks.mario_clock = sfClock_create();
    clocks.jump_clock = sfClock_create();
    clocks.gravity_clock = sfClock_create();
    clocks.cloud_clock = sfClock_create();
    clocks.parralaxmap = sfClock_create();
    return clocks;
}
