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

void startgame(back_t *back, mario_t **mario)
{
    if (sfKeyboard_isKeyPressed(sfKeyM) == sfTrue) {
        back->j = 1;
        (*mario)->carac = 0;
        sfSprite_destroy(back->start);
        sfTexture_destroy(back->my_start);
    }
    if (sfKeyboard_isKeyPressed(sfKeyL) == sfTrue) {
        back->j = 1;
        (*mario)->carac = 350;
        (*mario)->mariorect.left = (*mario)->carac;
        sfSprite_destroy(back->start);
        sfTexture_destroy(back->my_start);
    }
}

void backgroundreset(back_t **back)
{
    if ((*back)->z <= -1920)
        (*back)->z = 1920;
    if ((*back)->z2 <= -1920)
        (*back)->z2 = 1920;
    sfVector2f cloudpos = {(*back)->x, 0};
    sfVector2f cloudpos2 = {(*back)->x2, 0};
    sfVector2f midbackpos = {(*back)->y, 0};
    sfVector2f midbackpos2 = {(*back)->y2, 0};
    sfVector2f backbackpos = {(*back)->z, 0};
    sfVector2f backbackpos2 = {(*back)->z2, 0};
    sfSprite_setPosition((*back)->cloud, cloudpos);
    sfSprite_setPosition((*back)->backback, backbackpos);
    sfSprite_setPosition((*back)->backback2, backbackpos2);
    sfSprite_setPosition((*back)->cloud2, cloudpos2);
    sfSprite_setPosition((*back)->midback, midbackpos);
    sfSprite_setPosition((*back)->midback2, midbackpos2);
}

void backgroundmove(back_t *back, clocks_t *clocks)
{
    clocks->cloud_time = sfClock_getElapsedTime(clocks->cloud_clock);
    clocks->cloudsec = clocks->cloud_time.microseconds / 1000000.0;
    if (clocks->cloudsec > 0.01) {
        back->x -= 2;
        back->x2 -= 2;
        back->y -= 5;
        back->y2 -= 5;
        back->z -= 4;
        back->z2 -= 4;
        sfClock_restart(clocks->cloud_clock);
    }
    if (back->x <= -1920)
        back->x = 1920;
    if (back->x2 <= -1920)
        back->x2 = 1920;
    if (back->y2 <= -1920)
        back->y2 = 1920;
    if (back->y <= -1920)
        back->y = 1920;
    backgroundreset(&back);
}
