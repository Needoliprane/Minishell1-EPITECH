/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** exe_gen_check
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "../include/shell1.h"

int check_env_update(char **env)
{
    char *test = get_from_tab(env, "PATH=");

    if (test == NULL)
        return (-1);
    free(test);
    return (0);
}

int check_for_directory(char *str)
{
    DIR *dir = NULL;

    if (str == NULL)
            return (-1);
    if ((dir = opendir(str)) != NULL) {
        my_putstr(str);
        free(str);
        my_putstr(": Permission denied.\n");
        closedir(dir);
        return (-1);
    }
    return (0);
}

int check_error_exe(char *str, char **env)
{
    if (check_for_directory(str) == -1)
        return (-5);
    if (check_env_update(env) == -1)
        return (-1);
    return (0);
}