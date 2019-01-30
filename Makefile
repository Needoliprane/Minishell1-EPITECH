##
## EPITECH PROJECT, 2019
## PSU_minishell1_2018
## File description:
## Makefile
##

CC	=	gcc -g3

NAME	=	mysh

SRC	=	src/gnl/get_next_line.c					\
		src/ParsingPeg/peg_alloc_prep.c				\
		src/ParsingPeg/peg_destroy.c				\
		src/exe_gen.c						\
		src/ParsingPeg/peg_parser_tool.c			\
		src/ParsingPeg/peg_parser.c				\
		src/start_reading.c					\
		src/interpreter.c					\
		src/cd.c						\
		src/setenv.c						\
		src/unsetenv.c						\
		src/env.c						\
		src/exe_gen_check.c					\
		src/exit.c						\
		src/reading_helper.c					\
		src/get_file.c						\
		lib/my_count_para.c					\
		lib/my_str_to_word_array_shell.c			\
		lib/my_putstr.c						\
		lib/my_str_to_word_array_path.c				\
		lib/my_strdup.c						\
		lib/my_getnbr.c						\
		lib/my_strlen.c						\
		lib/tab_tool_next.c					\
		lib/tab_tool.c						\
		lib/my_str_to_word_array.c				\
		lib/my_strcmp.c						\


OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	 -I./include/ -W -Wextra -Wall

all: 		$(NAME)
		$(info )
		$(info "La doc, c'est comme le PQ: ça sert à se démerder tout seul")
		$(info )

$(NAME): 	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) src/main.c

clean:
		rm -f $(OBJ)

tests_run:
		$(CC) $(SRC) Tests/*.c --coverage -lcriterion -I./include
		./a.out

coverage_clean:
		rm -f *.gc*
		rm -f src/*.gc*

fclean: 	clean coverage_clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
