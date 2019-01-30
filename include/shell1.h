/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** shell1
*/

#ifndef SHELL1_H_
#define SHELL1_H_

/* Include */

#include "get_next_line.h"
#include "parser_peg.h"
#include "my.h"

/* Manage scripting shell */

char *get_tab(char const *str);

/* Reading commande LINE */

int start_read(peg_grammar_t *grammar, peg_parser_control_t *peg_c, char **env);
int check_command_line(char *tmp);
int cleaner(peg_parser_control_t *peg_c);
void my_prompt(void);
int parsing_and_interpreter(peg_grammar_t *grammar, peg_parser_control_t
							*peg_c, char *tmp);

/* Manage interpreter */

void interpreter_case_pair(peg_parser_control_t *peg_c);
void interpreter_case_impair(peg_parser_control_t *peg);
char *clean_str(char *tmp, char *ret);

/* Builtins */

int my_cd(peg_parser_control_t *peg);
int my_setenv(peg_parser_control_t *peg);
int my_unsetenv(peg_parser_control_t *peg);
int my_env(peg_parser_control_t *peg);
int my_exit(peg_parser_control_t *peg);
int my_cd_p(peg_parser_control_t *peg);
int check_error_cd(int check, char *path);
int my_setenv_p(peg_parser_control_t *peg);
int my_unsetenv_p(peg_parser_control_t *peg);
int my_env_p(peg_parser_control_t *peg);
int my_exit_p(peg_parser_control_t *peg);

/* Env helper */

char *get_from_tab(char **tab, char *str);
char **my_strcat_tab(char **tab, char *str);
char **remove_line(char *str, char **tab);

/* Exe_gen */

int exe_gen(peg_parser_control_t *peg);
int exe_gen_p(peg_parser_control_t *peg);
int check_env_update(char **env);
int check_error_exe(char *str, char **env);
int check_for_directory(char *str);

#endif /* !SHELL1_H_ */
