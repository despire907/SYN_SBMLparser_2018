/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#ifndef SBML_PARSER_REACT_H
#define SBML_PARSER_REACT_H

typedef struct reactant_s {
    char *stoichiometry;
    char *species;
    struct reactant_s *next;
}reactant_t;

reactant_t *manage_reactant(char *str);
reactant_t *find_info_reactant(char **str);
reactant_t *init_reactant(void);

#endif //SBML_PARSER_REACT_H
