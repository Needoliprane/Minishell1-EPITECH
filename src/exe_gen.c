/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** exe_gen
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/shell1.h"

void print_error(char *str)
{
    my_putstr(str);
    my_putstr(": Command not found.\n");
}

void check_pb_child(int wstatus)
{
    if (WIFSIGNALED(wstatus)) {
        if (WCOREDUMP(wstatus)) {
            my_putstr("Segmentation fault (core dumped)\n");
        } if (SIGFPE == wstatus) {
            my_putstr("Floating exception (coredumped)\n");
        } if (SIGFPE == wstatus && WCOREDUMP(wstatus)) {
            my_putstr("Segmentation fault (core dumped) && Floating Point");
            my_putstr("Floating exception.\n");
        }
    }
}

int execute(char *path, peg_parser_control_t *peg)
{
    pid_t pid = 0;
    int wstatus = 0;

    if ((pid = fork()) == 0)
        execve(path, peg->param, peg->env);
    else {
        wait(&wstatus);
        check_pb_child(wstatus);
        peg->ret = wstatus;
    }
    return (0);
}

int exe_gen(peg_parser_control_t *peg)
{
    char *tmp = NULL;
    int count = 0;

    count = check_error_exe(peg->peg[0].part1, peg->env);
    if (count == 0 && access(peg->peg[0].part1, X_OK) != -1)
        return (execute(peg->peg[0].part1, peg));
    for (int i = 0; count == 0 && peg->all_path[i]; i++) {
        tmp = my_strcat(peg->all_path[i], "/");
        tmp = my_strcat(tmp, peg->peg[peg->actual_deep].part1);
        if (access(tmp, X_OK) == 0) {
            execute(tmp, peg);
            count++;
        }
        free(tmp);
    }
    if (count == 0 || count == -1) {
        print_error(peg->peg[peg->actual_deep].part1);
        return (1);
    }
    return (0);
}

int exe_gen_p(peg_parser_control_t *peg)
{
    char *tmp = NULL;
    int count = 0;

    count = check_error_exe(peg->param[0], peg->env);
    if (count == 0 && access(peg->param[0], X_OK) != -1)
        return (execute(peg->param[0], peg));
    for (int i = 0; count == 0 && peg->all_path[i]; i++) {
        tmp = my_strcat(peg->all_path[i], "/");
        tmp = my_strcat(tmp, peg->param[0]);
        if (access(tmp, X_OK) == 0) {
            execute(tmp, peg);
            count++;
        }
        free(tmp);
    }
    if (count == 0 || count == -1) {
        print_error(peg->peg[peg->actual_deep].part1);
        return (1);
    }
    return (0);
}