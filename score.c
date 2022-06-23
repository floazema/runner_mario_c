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
#

void scoredisplay(back_t back, mario_t mario)
{
    sfVector2f textpos = {50, 50};
    char str[30] = "Score : ";
    char score[20];
    sfFont *font;
    sfText *text;

    my_strcpy(score, my_itoa(mario.intscore));
    my_strcpy(str, my_strcat(str, score));
    font = sfFont_createFromFile("assets/text.ttf");
    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setString(text, str);
    sfText_setPosition(text, textpos);
    if (back.j > 1) {
        sfVector2f textpos = {800, 50};
        sfText_setPosition(text, textpos);
    }
    sfRenderWindow_drawText(back.SuperMarioMaker, text, NULL);
}
