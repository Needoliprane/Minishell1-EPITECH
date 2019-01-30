/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** interpreter
*/

#include <stdio.h>
#include <stddef.h>
#include "../include/shell1.h"

char const *builtins[] = {"cd", "setenv", "unsetenv", "env", "exit", NULL};
int (*const list[6])(peg_parser_control_t *peg) =
{
    &my_cd, &my_setenv, &my_unsetenv, &my_env, &my_exit
};
int (*const list_1[6])(peg_parser_control_t *peg) =
{
    &my_cd_p, &my_setenv_p, &my_unsetenv_p, &my_env_p, &my_exit_p
};

void interpreter_case_pair(peg_parser_control_t *peg_c)
{
    char *tmp = NULL;
    int checker = 0;

    for (int i = 0, check_cmp = 0; builtins[i]; i++) {
        tmp = peg_c->peg[peg_c->actual_deep].part1;
        check_cmp = my_strcmp(tmp, builtins[i]);
        if (check_cmp == 0) {
            peg_c->ret = list[i](peg_c);
            checker++;
        }
        if (check_cmp == 184)
            return;
    }
    if (checker == 0)
        peg_c->ret = exe_gen(peg_c);
}

void interpreter_case_impair(peg_parser_control_t *peg)
{
    int checker = 0;

    for (int i = 0, check_cmp = 0; builtins[i]; i++) {
        check_cmp = my_strcmp(peg->param[0], builtins[i]);
        if (check_cmp == 0) {
            peg->ret = list_1[i](peg);
            checker++;
        }
        if (check_cmp == 184)
            return;
    }
    if (checker == 0)
        peg->ret = exe_gen_p(peg);
}