/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** putstr
*/

void my_putchar(char);

int my_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}
