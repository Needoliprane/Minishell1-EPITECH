/*
** EPITECH PROJECT, 2018
** nf.sh
** File description:
** nf
*/

#include <stdlib.h>
#include "../include/my.h"

char *clean_str(char *tmp, char *ret)
{
    int j = 0;

    for (int i = 0; tmp[i]; i++)
        (tmp[i] == ' ' || tmp[i] == '\t') ? j++ : j;
    if (my_strlen(tmp) == j)
        return (NULL);
    j = 0;
    for (int i = 0; tmp[i]; i++) {
        if ((tmp[i] == '\t' || tmp[i] == ' ') && is_num_alpha(tmp[i + 1])
                == 0) {
            (tmp[i] == '\t') ? tmp[i] = ' ' : tmp[i];
            ret[j] = tmp[i];
            (j == 0 && tmp[i] == ' ') ? j : j++;
        }
        else if (is_num_alpha(tmp[i]) == 0 || tmp[i] == '$')
            (i >= 0) ? ret[j] = tmp[i], j++ : 0;
    }
    ret[j] = '\0';
    free(tmp);
    return (ret);
}

int my_strcmp(char const *s1, char const *s2)
{
    if (s1 == NULL || s2 == NULL)
        return (184);
    if (s1[0] == '\0' || s2[0] == '\0')
        return (184);
    for (int i = 0; s1[i]; i++) {
        if (s1[i] != s2[i])
            return (s2[i] - s1[i]);
    }
    return (0);
}