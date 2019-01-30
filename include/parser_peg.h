/*
** EPITECH PROJECT, 2018
** Parsing Peg
** File description:
** parser_peg
*/

#ifndef PARSER_PEG_H_
#define PARSER_PEG_H_

/* Include */

#include <stdbool.h>

/* STRUCTUR GRAMMAR */

typedef struct peg_grammar_s {
    char *allowed_char;
    char *synthax_char;
} peg_grammar_t;

/* STRUCTUR PEG */

typedef struct peg_parser_s {
    char char_grammar;
    char *part1;
    char *part2;
} peg_parser_t;

typedef struct peg_parser_control {
    char **param;
    char **env;
    char **all_path;
    int ret;
    int deep;
    int write;
    int state;
    bool bol;
    int actual_deep;
    peg_parser_t *peg;
} peg_parser_control_t;

/* LIB include */

#include "my.h"

/* Set rules Peg */

peg_grammar_t *peg_set_grammar(char const *grammar, char const *allowed);

/* Prepare Parse Peg */

char *peg_malloc_part(int size);
int peg_count_recurence(char *str, peg_grammar_t *grammar);
peg_parser_control_t *peg_alloc(char *str, peg_grammar_t *grammar,
                                peg_parser_control_t *peg_control);

/* Parse Peg*/

void peg_parser(peg_grammar_t *grammar, peg_parser_control_t *peg, char *str);
bool peg_is_allowed_char(char stri, peg_grammar_t *grammar);
bool peg_is_grammar(char stri, peg_grammar_t *grammar);

/* Print Peg */

void peg_print(peg_parser_control_t *control_peg);

/* Destroy Peg */

void peg_destroy(peg_parser_control_t *peg_control);
void peg_destroy_all(peg_grammar_t *grammar, peg_parser_control_t
                                                    *peg_control);

#endif /* !PARSER_PEG_H_ */