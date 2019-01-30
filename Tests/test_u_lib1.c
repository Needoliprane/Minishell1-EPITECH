/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** test_u_lib
*/

#include <criterion/criterion.h>
#include "../include/shell1.h"

Test(count_para, count_para1)
{
    cr_assert(count_para("abcd", 'O') == 0);
}

Test(getnbr, getnbr1)
{
    cr_assert(my_getnbr("1") == 1);
}

Test(show_word_array, show_word_array1)
{
    cr_assert(show_word_array(NULL) == 0);
}