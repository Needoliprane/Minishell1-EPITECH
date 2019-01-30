/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** reading_helper
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/shell1.h"

void my_prompt(void)
{
    char *buf = malloc(sizeof(char) * 256);

    if (buf == NULL)
        return;
    for (int i = 0; i <= 255; i++)
        buf[i] = '\0';
    if (isatty(0) == 1) {
        my_putchar('[');
        getcwd(buf, 255);
        my_putstr(buf);
        my_putchar(']');
        my_putstr(" $> ");
    }
    free(buf);
}

int cleaner(peg_parser_control_t *peg_c)
{
    free_tab(peg_c->param);
    peg_destroy(peg_c);
    return (0);
}

int check_command_line(char *tmp)
{
    if (tmp == NULL)
        return (-1);
    if (my_strlen(tmp) < 3 && tmp[0] == '.' && (tmp[1] != '/'
                || tmp[1] == '.')) {
        my_putstr("/usr/bin/");
        my_putstr(tmp);
        my_putstr(": Permission denied.\n");
        return (-1);
    }
    if (tmp[0] == '$') {
        my_putstr(tmp + 1);
        my_putstr(": Undefined variable.\n");
        return (-1);
    }
    return (0);
}