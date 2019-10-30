/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#ifndef SBML_PARSER_REAACTION_H
#define SBML_PARSER_REAACTION_H

#include "product.h"
#include "react.h"

typedef struct react_s {
    char *compartment;
    char *reversible;
    char *name;
    char *id;
    prod_t *prod;
    reactant_t *reactant;
    struct react_s *next;
}react_t;

react_t *manage_reaction(char *str);
react_t *find_info_reaction(char **str, char *ptr);
react_t *init_reaction(char *str);

#endif //SBML_PARSER_REAACTION_H
