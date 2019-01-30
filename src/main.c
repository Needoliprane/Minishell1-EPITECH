/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** main
*/

#include <stdlib.h>
#include "../include/shell1.h"

char const *allowed = "abcdefghijklmnopqrstuvwxyzABCEDFGHIJ";
char const *allowed1 = "KLMNOPQRSTUVWXYZ0123456789/.-_";
char const *grammar_c = " ;<>";

int main(int ac, char **av, char **env)
{
    char *allowed_f = my_strcat((char *)allowed, (char *)allowed1);
    peg_grammar_t *grammar = peg_set_grammar(grammar_c, allowed_f);
    peg_parser_control_t *peg_control = malloc(sizeof(peg_parser_control_t));
    int ret = 0;

    if (env == NULL || grammar == NULL || peg_control == NULL ||
                allowed_f == NULL)
        return (84);
    peg_control->env = tap_copy(env);
    peg_control->ret = 0;
    if (ac != 1)
        return (84);
    (void)av;
    ret = start_read(grammar, peg_control, peg_control->env);
    return (ret);
}