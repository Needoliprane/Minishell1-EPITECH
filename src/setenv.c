/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** setenv
*/

#include <stdlib.h>
#include "../include/shell1.h"

int my_setenv_p_other_case(peg_parser_control_t *peg, char *tmp, char *test)
{
    if (peg->param[1] != NULL && peg->param[2] == NULL) {
        tmp = my_strcat(peg->param[1], "=");
        if ((test = get_from_tab(peg->env, tmp)) != NULL)
            peg->env = remove_line(tmp, peg->env);
        peg->env = my_strcat_tab(peg->env, tmp);
    }
    if (peg->param[1] != NULL && peg->param[2] != NULL) {
        tmp = my_strcat(peg->param[1], "=");
        if ((test = get_from_tab(peg->env, tmp)) != NULL)
            peg->env = remove_line(tmp, peg->env);
        tmp = my_strcat(tmp, peg->param[2]);
        peg->env = my_strcat_tab(peg->env, tmp);
    }
    if (test != NULL) {
        free(test);
        free(tmp);
    }
    return (0);
}

int error_env(char *str)
{
    if ((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z')) {
        return (0);
    }
    my_putstr("setenv: Variable name must begin with a letter.\n");
    return (-1);
}

int my_setenv_p(peg_parser_control_t *peg)
{
    char *tmp = NULL;
    char *test = NULL;

    if (my_strlen_tab(peg->param) > 3) {
        my_putstr("setenv: Too many arguments.\n");
        return (1);
    }
    if (peg->param[1] == NULL)
        return (my_env(peg));
    if (error_env(peg->param[1]) == -1)
        return (1);
    my_setenv_p_other_case(peg, tmp, test);
    return (0);
}

int my_setenv(peg_parser_control_t *peg)
{
    return (my_setenv_p(peg));
}