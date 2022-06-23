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

back_t my_events(back_t back, mario_t *mario)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(back.SuperMarioMaker, &event)) {
        if (event.type == sfEvtClosed || event.key.code == sfKeyEscape) {
            sfMusic_destroy(back.musicf);
            sfRenderWindow_close(back.SuperMarioMaker);
        }
        if (event.type == sfEvtKeyPressed && back.j < 1) {
            startgame(&back, &mario);
        }
    }
    return back;
}

void drawsprite(back_t back)
{

    sfSprite *tab[] = {back.cloud, back.cloud2, back.backback,
    back.backback2, back.midback, back.midback2};
    if (back.j < 1)
        sfRenderWindow_drawSprite(back.SuperMarioMaker, back.start, NULL);
    if (back.j == 1)
        for (int i = 0; i < 6; i++)
            sfRenderWindow_drawSprite(back.SuperMarioMaker, tab[i], NULL);
    if (back.j == 2) {
        sfRenderWindow_drawSprite(back.SuperMarioMaker, back.end, NULL);
    }
    if (back.j == 3) {
        sfRenderWindow_drawSprite(back.SuperMarioMaker, back.win, NULL);
    }
}

void mariomove(mario_t *mario, clocks_t *clocks)
{
    clocks->mario_time = sfClock_getElapsedTime(clocks->mario_clock);
    mario->mario_sec = clocks->mario_time.microseconds / 1000000.0;
        if (mario->mario_sec > 0.15) {
            mario->intscore += 100;
            sfClock_restart(clocks->mario_clock);
            mario->mariorect.left += 88;
        }
    if (mario->mariorect.left >= mario->carac + 280)
        mario->mariorect.left = mario->carac;
}

int errorhandling(int argc, char **av)
{
    if (argc != 2)
        return 84;
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        my_putstr("\nSupermarioMaker !, press space or upper key to jump \
the goal of the game is to end the game for that touch the flag\
\n\nUSAGE:\n\n ./my_runner maps/[map you want]\n You have to be at\
the root or the programm return 84, Good luck have fun\n\n");
        return (84);
    }
    int fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (84);
    if (sfMusic_createFromFile("assets/mario music.ogg") == NULL)
        return (84);
    if (sfMusic_createFromFile("assets/saut.ogg") == NULL)
        return (84);
    return (0);
}

int main(int argc, char **argv)
{
    if (errorhandling(argc, argv) == 84)
        return 84;
    back_t back = my_init();
    mario_t mario = mario_init();
    clocks_t clocks = clocks_init();
    mapelement_t maps = my_maps(maps, argv);

    while (sfRenderWindow_isOpen(back.SuperMarioMaker)) {
        sfRenderWindow_clear(back.SuperMarioMaker, sfBlack);
        back = my_events(back, &mario), drawsprite(back);
        if (back.j >= 1)
            scoredisplay(back, mario);
        if (back.j == 1) {
            mario = jumpclock(mario, &clocks, back);
            gravity(maps, &mario, &back);
            mariomove(&mario, &clocks), printmap(&maps, &back, mario);
            moovemap(&maps, &clocks), hitbox(&back, mario, maps);
            backgroundmove(&back, &clocks);
        }
        sfRenderWindow_display(back.SuperMarioMaker);
    }
}
