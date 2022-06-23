/*
** EPITECH PROJECT, 2021
** my.h library
** File description:
** my.h :(
*/

#ifndef MY_H_
    #define MY_H_
	#include <SFML/Graphics.h>
	#include <SFML/Window.h>
	#include <SFML/System.h>
	#include <./struct.h>
char *my_strdup(char const *src);
int my_print_alpha(void);
int my_print_revalpha(void);
void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
char *my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(char const *str);
char *itoa(int);
void backgroundmove(back_t *back, clocks_t *clocks);
void backgroundreset(back_t **back);
void startgame(back_t *back, mario_t **mario);
void checkcolision(mapelement_t *maps, back_t **back, mario_t mario);
void printobjectmap(mapelement_t *maps, back_t *back, mario_t mario,
int count);
void gravity(mapelement_t maps, mario_t *mario, back_t *back);
void hitbox(back_t *back, mario_t mario, mapelement_t maps);
char *itoa(int num);
void scoredisplay(back_t back, mario_t mario);
void others(back_t *back);
void spritecreate(back_t *back);
back_t my_init(void);
mario_t mario_init(void);
clocks_t clocks_init(void);
void printmap(mapelement_t *maps, back_t *back, mario_t mario);
void createmap(mapelement_t *maps, char **av);
void maptexture(mapelement_t *maps);
mapelement_t my_maps(mapelement_t maps, char **av);
void moovemap(mapelement_t *maps, clocks_t *clocks);
void jump2(mario_t **mario);
void jump(mario_t *mario, back_t back);
mario_t jumpclock(mario_t mario, clocks_t *clocks, back_t back);
#endif/*__MY_H__*/
