/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#ifndef SBML_PARSER_COMP_H
#define SBML_PARSER_COMP_H

typedef struct compartment_s {
    char *name;
    char *id;
    struct compartment_s *next;
}compartment_t;

int my_strcmp(char const *s1, char const *s2);
compartment_t *init_comp(void);
int nb_of_name(char **str, int i);
char *give_name(char **str, int i);
compartment_t *find_info_comp(char **str);
compartment_t *manage_comp(char *str);

#endif //SBML_PARSER_COMP_H
