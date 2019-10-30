/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#ifndef SBML_PARSER_SBML_H
#define SBML_PARSER_SBML_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <search.h>
#include <assert.h>
#include "comp.h"
#include "model.h"
#include "species.h"
#include "reaction.h"

typedef struct sbml_s {
    char *xmlns;
    char *level;
    char *version;
    struct sbml_s *next;
}sbml_t;

#include "info.h"

char *get_file(void);
char *get_line(void);
FILE *open_file(char const *filepath);
int alpha_num(char car);
int count_char(char const *str);
int count_word(char const *str);
char **my_str_to_word_array_synthesis(char const *str);
sbml_t *manage_sbml(char *str);
sbml_t *find_info_sbml(char **str);
sbml_t *init_sbml(void);
int list_of_arg(char **av);
void free_tab(char **tab);
void free_reactant(reactant_t *reactant);
void free_prod(prod_t *prod);
void free_react(react_t *react);
void free_species(species_t *species);
void free_sbml(sbml_t *sbml);
void free_mod(model_t *mod);
void free_comp(compartment_t *comp);
void redirect_all_std(void);
int sbmlparser(int ac, char **av);

#endif //SBML_PARSER_SBML_H
