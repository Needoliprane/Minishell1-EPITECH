/*
** EPITECH PROJECT, 2018
** Parsing Peg
** File description:
** peg_destroy
*/

#include <stdlib.h>
#include "../../include/parser_peg.h"

void peg_destroy(peg_parser_control_t *peg_control)
{
    for (int i = 0; i < peg_control->deep; i++) {
        free(peg_control->peg[i].part1);
        if (peg_control->peg[i].part2 != NULL)
            free(peg_control->peg[i].part2);
        peg_control->peg[i].part1 = NULL;
        peg_control->peg[i].part2 = NULL;
    }
    free(peg_control->peg);
}

void peg_destroy_all(peg_grammar_t *grammar, peg_parser_control_t *peg_control)
{
    if (grammar != NULL) {
        free(grammar->allowed_char);
        free(grammar->synthax_char);
        free(grammar);
    }
    peg_destroy(peg_control);
    free_tab(peg_control->param);
    free_tab(peg_control->env);
    free(peg_control);
}