/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** exit
*/

#include <stdlib.h>
#include <stddef.h>
#include "../include/shell1.h"

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (0);
    return (1);
}

int my_exit(peg_parser_control_t *peg)
{
    int exit_value = 0;

    if (peg != NULL && peg->peg[peg->actual_deep].part2 != NULL)
        exit_value = my_getnbr(peg->peg[peg->actual_deep].part2);
    for (int i = 0; peg->peg[peg->actual_deep].part2[i]; i++) {
        if (i == 0 && is_num(peg->peg[peg->actual_deep].part2[i]) == 1) {
            my_putstr("exit: Expression Syntax.\n");
            return (1);
        }
        if (i > 0 && is_num(peg->peg[peg->actual_deep].part2[i]) == 1) {
            my_putstr("exit: Badly formed number.\n");
            return (1);
        }
    }
    if (peg != NULL)
        peg_destroy_all(NULL, peg);
    exit(exit_value);
    return (0);
}

int my_exit_p(peg_parser_control_t *peg)
{
    if (my_strlen_tab(peg->param) > 2) {
        my_putstr("exit: Expression Syntax.\n");
        if (peg != NULL)
            peg_destroy_all(NULL, peg);
        exit(1);
    }
    return (my_exit(peg));
}