/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** cd
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/shell1.h"

int check_error_cd(int check, char *path)
{
    struct stat sb;

    if (check == -1) {
        if (stat(path, &sb) == 0) {
            my_putstr(path);
            my_putstr(": Not a directory.\n");
        }
        else if (path[0] != '-' && path != NULL) {
            my_putstr(path);
            my_putstr(": No such file or directory.\n");
        }
        return (1);
    }
    return (0);
}

char **update_env_cd(char **env, char *path)
{
    char *actual_f = get_from_tab(env, "PWD=") + 4;
    char *buf = malloc(sizeof(char) * 256);

    for (int i = 0; i <= 255; i++)
        buf[i] = '\0';
    getcwd(buf, 255);
    path = my_strcat("/", path);
    env = remove_line("PWD=", env);
    env = remove_line("OLDPWD=", env);
    env = my_strcat_tab(env, my_strcat("PWD=", buf));
    env = my_strcat_tab(env, my_strcat("OLDPWD=", actual_f));
    free(buf);
    return (env);
}

int cd_home(peg_parser_control_t *peg)
{
    char *tmp = get_from_tab(peg->env, "HOME=");

    if (tmp == NULL) {
        my_putstr(": No such file or directory.\n");
        return (1);
    }
    if (chdir(tmp + 5) == -1) {
        check_error_cd(-1, tmp + 5);
        return (1);
    }
    peg->env = update_env_cd(peg->env, tmp);
    return (0);
}

int my_cd(peg_parser_control_t *peg)
{
    int check = 0;

    if (peg->peg[peg->actual_deep].part2[0] == '\0')
        return (cd_home(peg));
    if (peg->peg[peg->actual_deep].part2[0] != '\0') {
        if (peg->peg[peg->actual_deep].part2[0] != '-' &&
                    peg->peg[peg->actual_deep].part2[0] != '.')
            check = chdir(peg->peg[peg->actual_deep].part2);
        else if (peg->peg[peg->actual_deep].part2[0] == '.')
            check = chdir(peg->peg[peg->actual_deep].part2);
        else
            check = chdir(get_from_tab(peg->env, "OLDPWD=") + 7);
    }
    if (check_error_cd(check, peg->peg[peg->actual_deep].part2) == 1)
        return (1);
    peg->env = update_env_cd(peg->env, peg->peg[0].part2);
    return (0);
}

int my_cd_p(peg_parser_control_t *peg)
{
    if (peg == NULL)
        return (1);
    my_cd(peg);
    return (0);
}