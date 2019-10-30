/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#ifndef SBML_PARSER_SPECIES_H
#define SBML_PARSER_SPECIES_H

typedef struct species_s {
    char *compartment;
    char *name;
    char *id;
    struct species_s *next;
}species_t;

species_t *manage_species(char *str);
species_t *find_info_species(char **str);
species_t *init_species(void);

#endif //SBML_PARSER_SPECIES_H
