/*
** EPITECH PROJECT, 2018
** Parsing Peg
** File description:
** my_count_para
*/

#include <stdlib.h>
#include "../include/my.h"

int count_para(char const *str, char c)
{
    int count = 0;

    for (int i = 0; str && str[i]; i++)
        if (str[i] == c)
            count++;
    return (count);
}

char *my_strcat(char *buf, char *tmp)
{
    int j = 0;
    int len1 = my_strlen(buf);
    char *new_tmp = malloc(sizeof(char) * (len1 + my_strlen(tmp) + 1));

    if (new_tmp == NULL)
        return (NULL);
    for (;buf[j]; j++)
        new_tmp[j] = buf[j];
    for (int i = 0; tmp[i]; j++, i++)
        new_tmp[j] = tmp[i];
    new_tmp[j] = '\0';
    return (new_tmp);
}