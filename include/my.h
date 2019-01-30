/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

int is_num_alpha(char c);
char *my_strdup(char const *str);
int count_para(char const *str, char c);
int my_strlen(char const *str);
void my_putstr(char *str);
void my_putchar(char c);
int my_strlen_tab(char **av);
char **tap_copy(char **map);
void free_tab(char **map);
char **my_str_to_word_array(char const *str);
int show_word_array(char **tab);
int my_strcmp(char const *s1, char const *s2);
int my_getnbr(char const *str);
char *my_strcat(char *buf, char *tmp);
char **my_word_to_array_path(char *str, char c);
char **my_str_to_word_array_script(char const *str);

#endif /* !MY_H_ */
