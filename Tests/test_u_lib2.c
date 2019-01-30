/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** test_u_lib
*/

#include <criterion/criterion.h>
#include "../include/shell1.h"

Test(my_strcmp, my_strcmp1)
{
    cr_assert(my_strcmp(NULL, NULL) == 184);
}

Test(my_strlen, my_strlen1)
{
    cr_assert(my_strlen("1") == 1);
}