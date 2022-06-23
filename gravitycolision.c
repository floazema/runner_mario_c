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

void checkcolision(mapelement_t *maps, back_t **back, mario_t mario)
{
    sfVector2f mario_pos = sfSprite_getPosition(mario.sprite_mario);
    sfVector2f goomba_pos = sfSprite_getPosition(maps->goomba);

    if (mario_pos.x + 80 >= goomba_pos.x && mario_pos.x + 80 \
<= goomba_pos.x + 64 && mario_pos.y + 170 >= goomba_pos.y \
&& mario_pos.y <= goomba_pos.y + 64) {
        (*back)->j = 2;
    }
}

void printobjectmap(mapelement_t *maps, back_t *back, mario_t mario, int count)
{
    if (maps->map[count] == 'g') {
        sfSprite_setPosition(maps->grass, maps->objct_pos);
        sfRenderWindow_drawSprite(back->SuperMarioMaker, maps->grass, NULL);
    }
    if (maps->map[count] == 's') {
        sfSprite_setPosition(maps->ground, maps->objct_pos);
        sfRenderWindow_drawSprite(back->SuperMarioMaker, maps->ground, NULL);
    }
    if (maps->map[count] == 'e') {
        sfSprite_setPosition(maps->goomba, maps->objct_pos);
        sfRenderWindow_drawSprite(back->SuperMarioMaker, maps->goomba, NULL);
        checkcolision(maps, &back, mario);
    }
    if (maps->map[count] == 'b') {
        sfSprite_setPosition(maps->block, maps->objct_pos);
        sfRenderWindow_drawSprite(back->SuperMarioMaker, maps->block, NULL);
    }
    if (maps->map[count] == 'f') {
        sfSprite_setPosition(maps->flag, maps->objct_pos);
        sfRenderWindow_drawSprite(back->SuperMarioMaker, maps->flag, NULL);
    }
}

void gravity(mapelement_t maps, mario_t *mario, back_t *back)
{
    int i = 0;
    int count = 0;
    float floattoint = 4.0;
    sfVector2f  my_mario_pos = {256, mario->height};

    floattoint += (maps.parralax / 64.0) * -1.0;
    count = floattoint;
    mario->isfall = 0;
    for (i = 0; maps.map[count] != 'g' &&
    maps.map[count] != 's' && maps.map[count] != 'b'; i++)
        count = count + maps.linelength + 1;
    if (mario->height + 177 < i * 64) {
        mario->isfall = 1;
        mario->height += 10;
    }
    if ((mario->height + 160 > i * 64 && mario->isfall == 0
    && maps.map[count] != 'b') || mario->height > 950)
        back->j = 2;
    sfSprite_setPosition(mario->sprite_mario, my_mario_pos);
}

void hitbox(back_t *back, mario_t mario, mapelement_t maps)
{
    sfVector2f Flag_pos;
    sfVector2f Mario_pos;
    Mario_pos = sfSprite_getPosition(mario.sprite_mario);
    Flag_pos = sfSprite_getPosition(maps.flag);
    if (Mario_pos.x + 50 >= Flag_pos.x) {
        back->j = 3;
    }
}
