/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** test_u_lib
*/

#include <criterion/criterion.h>
#include "../include/shell1.h"

Test(my_cd_p, my_cd_p)
{
    cr_assert(my_cd_p(NULL) == 1);
}

Test(check_error_cd, check_error_cd)
{
    cr_assert(check_error_cd(0, "lol") == 0);
}

Test(my_env, my_env)
{
    cr_assert(my_env(NULL) == 1);
}

Test(check_for_directory, check_for_directory)
{
    cr_assert(check_for_directory(NULL) == -1);
}