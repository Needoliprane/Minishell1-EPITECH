/*
** EPITECH PROJECT, 2018
** Parsing Peg
** File description:
** my_putstr
*/

#include <unistd.h>

void my_putstr(char *str)
{
    int i = 0;

    for (; str[i]; i++);
    write(1, str, i);
}

int show_word_array(char **tab)
{
    if (tab == NULL) {
        my_putstr("tab == NULL\n");
        return (0);
    }
    for (int i = 0; tab && tab[i]; i++) {
        my_putstr(tab[i]);
        my_putstr("\n");
    }
    return (0);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}