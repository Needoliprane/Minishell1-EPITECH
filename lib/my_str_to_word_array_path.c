/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_str_to_word_array_path
*/


#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

char *my_clean_malloc(char *str, int j)
{
    str = malloc(sizeof(char) * (j + 2));
    if (str == NULL)
        exit (84);
    for (int i = 0; i < (j + 2); i++)
        str[i] = '\0';
    return (str);
}

char **my_word_to_array2(char **argv, char *str, char c, int j)
{
    for (int i = 0, a = 0, j = 0; str[i]; i++) {
        if (str[i] != c) {
            argv[j][a] = str[i];
            a++;
        }
        else if (str[i] == c || str[i] <= 33) {
            argv[j][a] = '\0';
            j++;
            a = 0;
        }
    }
    argv[j + 1] = NULL;
    return (argv);
}

char **my_word_to_array_path(char *str, char c)
{
    char **argv = NULL;
    int j = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            j++;
    }
    argv = malloc(sizeof(char *) * (j + 2));
    argv[0] = NULL;
    for (int k = 0, j = 0, n = 0; str[k]; k++) {
        if (str[k] == c)
            j++;
        if (str[k + 1] == '\0' || str[k] == c) {
            argv[n] = my_clean_malloc(argv[n], k);
            n++;
            j = 0;
        }
    }
    argv = my_word_to_array2(argv, str, c, j);
    return (argv);
}