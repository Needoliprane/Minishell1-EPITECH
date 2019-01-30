/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** tab_tool
*/

#include <stdlib.h>
#include "../include/my.h"

void free_tab(char **map)
{
    for (int i = 0; map && i <= my_strlen_tab(map); i++) {
        free(map[i]);
    }
    free(map);
}

char **tap_copy(char **map)
{
    char **tmp = NULL;
    int i = 0;

    if (map == NULL)
        return (NULL);
    tmp = malloc(sizeof(char *) * (my_strlen_tab(map) + 1));
    if (tmp == NULL)
        return (NULL);
    for (; tmp && map[i]; i++) {
        tmp[i] = my_strdup(map[i]);
    }
    if (tmp)
        tmp[i] = NULL;
    return (tmp);
}