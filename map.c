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

void printmap(mapelement_t *maps, back_t *back, mario_t mario)
{
    int y = 0;
    int x = 0;
    int count = 0;

    while (maps->map[count] != '\0') {
        if (maps->map[count] == '\n') {
            y += 64;
            x = maps->parralax;
        }
        printobjectmap(maps, back, mario, count);
        maps->objct_pos.x = x;
        maps->objct_pos.y = y;
        x += 64;
        count++;
    }
}

void createmap(mapelement_t *maps, char **av)
{
    int i = 0;
    int fd = open(av[1], O_RDONLY);

    maps->map = malloc((10000) + 1);
    read(fd, maps->map, (10000));
    maps->map[my_strlen(maps->map)] = '\0';
    for (i = 0; maps->map[i] != '\n'; i++);
    maps->linelength = i;
    close(fd);
}

void maptexture(mapelement_t *maps)
{
    maps->my_grass = sfTexture_createFromFile("assets/grass.png", NULL);
    maps->grass = sfSprite_create();
    maps->my_ground = sfTexture_createFromFile("assets/sol.png", NULL);
    maps->ground = sfSprite_create();
    maps->my_goomba = sfTexture_createFromFile("assets/goomba.png", NULL);
    maps->goomba = sfSprite_create();
    maps->my_block = sfTexture_createFromFile("assets/brique.png", NULL);
    maps->block = sfSprite_create();
    maps->my_flag = sfTexture_createFromFile("assets/flagd.png", NULL);
    maps->flag = sfSprite_create();
    sfSprite_setTexture(maps->flag, maps->my_flag, sfTrue);
    sfSprite_setTexture(maps->goomba, maps->my_goomba, sfTrue);
    sfSprite_setTexture(maps->block, maps->my_block, sfTrue);
    sfSprite_setTexture(maps->grass, maps->my_grass, sfTrue);
    sfSprite_setTexture(maps->ground, maps->my_ground, sfTrue);
}

mapelement_t my_maps(mapelement_t maps, char **av)
{
    maps.parralax = 0;
    createmap(&maps, av);
    maptexture(&maps);
    return (maps);
}

void moovemap(mapelement_t *maps, clocks_t *clocks)
{
    clocks->parralaxmaptime = sfClock_getElapsedTime(clocks->parralaxmap);
    clocks->mapsec = clocks->parralaxmaptime.microseconds / 1000000.0;
    if (clocks->mapsec > 0.02) {
        maps->parralax -= 17;
        sfClock_restart(clocks->parralaxmap);
    }
}
