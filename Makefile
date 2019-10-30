##
## EPITECH PROJECT, 2018
## MUL_my_defender_2018
## File description:
## makefile
##

CC	= gcc -g

RM	= rm -rf

NAME	= SBMLparser

TEST_NAME	= test

MAIN	= src/main.c

SRC	= src/utils/open_file.c   \
	src/compartment/give_comp.c   \
	src/compartment/comp_return.c \
	src/info/init_info.c  \
	src/model/give_model.c    \
	src/sbml/give_sbml.c \
	src/species/give_species.c    \
	src/reaction/give_reaction.c  \
	src/reaction/product/give_prod.c  \
	src/reaction/reactant/give_reactant.c  \
	src/utils/display.c \
	src/utils/my_strtowordarray_synthesis.c  \
	src/argument/arg_of_sbml.c    \
	src/argument/manage_arg.c \
	src/argument/check_id.c   \
	src/argument/manage_id.c  \
	src/reaction/display_react.c  \
	src/argument/manage_cal.c \
	src/free/free_all.c   \
	src/free/free_react.c

TEST_SRC = tests/simple_test.c  \
			tests/i_option_test.c

TEST_OBJ = $(TEST_SRC:.c=.o)

OBJ	= $(SRC:.c=.o)

MAIN_OBJ	= $(MAIN:.c=.o)

CFLAGS	= -W -Wextra -Wall -I include/

$(NAME): $(OBJ) $(MAIN_OBJ)
	$(CC) $(OBJ) $(MAIN_OBJ) -o $(NAME)

all:	$(NAME)

tests_run: $(OBJ) $(TEST_OBJ)
	gcc $(TEST_OBJ) -o $(TEST_NAME) --coverage -lcriterion $(OBJ) -I include/
	./$(TEST_NAME)

clean:
	$(RM) $(OBJ) $(TEST_OBJ) $(MAIN_OBJ) */*/*/*.gcda */*/*/*.gcno */*/*.gcda */*/*.gcno */*.gcda */*.gcno

fclean: clean
	$(RM) $(NAME) $(TEST_NAME)

re:	fclean all

.PHONY: all clean fclean re
