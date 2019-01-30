/*
** EPITECH PROJECT, 2018
** Parsing Peg
** File description:
** my_strlen
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (-1);
    for (; str[i]; i++);
    return (i);
}

int my_strlen_tab(char **av)
{
    int i = 0;

    for (; av && av[i]; i++);
    return (i);
}