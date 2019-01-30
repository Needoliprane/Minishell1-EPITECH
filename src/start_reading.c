/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** start_reading
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/shell1.h"

int check_if_scirpt(char *tmp)
{
    int len = my_strlen(tmp);
    int count = 0;

    if (tmp[len - 1] == 'h')
        count++;
    if (tmp[len - 2] == 's')
        count++;
    if (tmp[len - 3] == '.')
        count++;
    if (count == 3)
        return (1);
    return (0);
}

void else_maker_norm(peg_grammar_t *grammar, peg_parser_control_t *peg_c,
                char *tmp)
{
    char *ret = NULL;
    char **file = NULL;

    if (access(tmp, X_OK) == 0 && check_if_scirpt(tmp) == 1) {
        if ((ret = get_tab(tmp)) == NULL)
            return;
        file = my_str_to_word_array_script(ret);
        for (int i = 0, len = my_strlen_tab(file); i < len ; i++)
            parsing_and_interpreter(grammar, peg_c, file[i]);
        free_tab(file);
        free(tmp);
        free(ret);
        return;
    }
    ret = malloc(sizeof(char) * (my_strlen(tmp) + 1));
    tmp = clean_str(tmp, ret);
    parsing_and_interpreter(grammar, peg_c, tmp);
    free(tmp);
}

int parsing_and_interpreter(peg_grammar_t *grammar, peg_parser_control_t
                    *peg_c, char *tmp)
{
    int len_tab = 0;

    if (check_command_line(tmp) == -1)
        return (0);
    peg_c = peg_alloc(tmp, grammar, peg_c);
    peg_parser(grammar, peg_c, tmp);
    peg_c->param = my_str_to_word_array(tmp);
    len_tab = my_strlen_tab(peg_c->param);
    if (len_tab % 2 != 0 && len_tab > 2)
        interpreter_case_impair(peg_c);
    if (len_tab % 2 == 0 || len_tab < 2)
        interpreter_case_pair(peg_c);
    cleaner(peg_c);
    return (peg_c->ret);
}

int start_read(peg_grammar_t *grammar, peg_parser_control_t *peg_c, char **env)
{
    char *list_path = get_from_tab(env, "PATH=");
    int ret = 0;

    if ((peg_c->all_path = my_word_to_array_path(list_path + 5, ':')) == NULL)
        return (84);
    if ((peg_c->env = remove_line("OLDPWD", peg_c->env)) == NULL)
        return (84);
    for (char *tmp = NULL ;;) {
        my_prompt();
        tmp = get_next_line(0);
        if (tmp == NULL)
            return (peg_c->ret);
        else
            else_maker_norm(grammar, peg_c, tmp);
    }
    ret = peg_c->ret;
    peg_destroy_all(grammar, peg_c);
    return (ret);
}