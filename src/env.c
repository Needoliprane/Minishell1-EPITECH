/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** env
*/

#include <stddef.h>
#include "../include/shell1.h"

void print_error_env(char *tmp)
{
    my_putstr("env: ‘");
    my_putstr(tmp);
    my_putstr("‘: No such file or directory\n");
}

int my_env(peg_parser_control_t *peg)
{
    if (peg == NULL)
        return (1);
    if (peg->peg[peg->actual_deep].part2[0] != '\0') {
        print_error_env(peg->peg[peg->actual_deep].part2);
        return (0);
    }
    show_word_array(peg->env);
    return (0);
}

int my_env_p(peg_parser_control_t *peg)
{
    if (my_strlen_tab(peg->param) > 1) {
        print_error_env(peg->param[1]);
        return (0);
    }
    show_word_array(peg->env);
    return (0);
}