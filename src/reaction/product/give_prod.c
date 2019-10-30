/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "sbml.h"

prod_t *init_prod(void)
{
    prod_t *new = malloc(sizeof(prod_t));

    new->stoichiometry = NULL;
    new->species = NULL;
    new->next = NULL;

    return new;
}

prod_t *find_info_prod(char **str)
{
    prod_t *new = init_prod();
    prod_t *begin = new;
    int i = 1;

    while (my_strcmp(str[i], "/listOfProducts")) {
        if (!my_strcmp(str[i], "stoichiometry")) {
            i++;
            new->stoichiometry = str[i];
        } if (!my_strcmp(str[i], "species")) {
            i++;
            new->species = str[i];
        } if (!my_strcmp(str[i], "speciesReference") && new->stoichiometry !=
        NULL && new->next == NULL) {
            new->next = init_prod();
            new = new->next;
        }
        i++;
    }
    new = begin;
    return new;
}

prod_t *manage_prod(char *str)
{
    prod_t *prod;
    char *check = NULL;
    char **tab = NULL;

    if ((check = strstr(str, "listOfProducts")) == NULL)
        return NULL;
    else {
        tab = my_str_to_word_array_synthesis(check);
        prod = find_info_prod(tab);
    }
    return prod;
}