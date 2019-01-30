/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** unsetenv
*/

#include <stddef.h>
#include "../include/shell1.h"

int my_unsetenv(peg_parser_control_t *peg)
{
    return (my_unsetenv_p(peg));
}

int my_unsetenv_p(peg_parser_control_t *peg)
{
    if (peg->param[1] == NULL) {
        my_putstr("unsetenv: Too few arguments.\n");
        return (1);
    }
    for (int i = 1; peg->param[i] != NULL; i++) {
        peg->env = remove_line(peg->param[i], peg->env);
    }
    return (0);
}