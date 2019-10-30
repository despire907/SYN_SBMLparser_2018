/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#ifndef SBML_PARSER_PRODUCT_H
#define SBML_PARSER_PRODUCT_H

typedef struct prod_s {
    char *stoichiometry;
    char *species;
    struct prod_s *next;
}prod_t;

prod_t *manage_prod(char *str);
prod_t *find_info_prod(char **str);
prod_t *manage_prod(char *str);

#endif //SBML_PARSER_PRODUCT_H
