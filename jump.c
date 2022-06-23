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

void jump2(mario_t **mario)
{
    if ((*mario)->isjump == 1) {
        (*mario)->airtime += 1;
        (*mario)->height -= 20;
    }
    if ((*mario)->airtime > 28)
        (*mario)->isjump = 2;
    if ((*mario)->isjump == 2) {
        (*mario)->isjump = 0;
        (*mario)->airtime = 0;
        sfMusic_destroy((*mario)->jumpsound);
        (*mario)->jumpsound = sfMusic_createFromFile("assets/saut.ogg");
    }
}

void jump(mario_t *mario, back_t back)
{
    sfVector2f  my_mario_pos_jump = {190, mario->height};

    if ( back.j > 0 && mario->isjump < 1 && \
    (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue
    || sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) && mario->isfall == 0) {
        mario->isjump = 1;
        sfMusic_play(mario->jumpsound);
    }
    jump2(&mario);
    sfSprite_setPosition(mario->sprite_mario, my_mario_pos_jump);
}

mario_t jumpclock(mario_t mario, clocks_t *clocks, back_t back)
{

    sfSprite_setTextureRect(mario.sprite_mario, mario.mariorect);
    sfRenderWindow_drawSprite(back.SuperMarioMaker, mario.sprite_mario, NULL);
    clocks->jump_time = sfClock_getElapsedTime(clocks->jump_clock);
    clocks->jumpsec = clocks->jump_time.microseconds / 1000000.0;
        if (clocks->jumpsec > 0.01) {
            jump(&mario, back);
            sfClock_restart(clocks->jump_clock);
        }
    return mario;
}
