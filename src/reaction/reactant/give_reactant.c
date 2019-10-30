/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "sbml.h"

reactant_t *init_reactant(void)
{
    reactant_t *new = malloc(sizeof(reactant_t));

    new->stoichiometry = NULL;
    new->species = NULL;
    new->next = NULL;

    return new;
}

reactant_t *find_info_reactant(char **str)
{
    reactant_t *new = init_reactant();
    reactant_t *begin = new;
    int i = 1;

    while (my_strcmp(str[i], "/listOfReactants")) {
        if (!my_strcmp(str[i], "stoichiometry")) {
            i++;
            new->stoichiometry = str[i];
        } if (!my_strcmp(str[i], "species")) {
            i++;
            new->species = str[i];
        } if (!my_strcmp(str[i], "speciesReference") && new->stoichiometry !=
        NULL && new->next == NULL) {
            new->next = init_reactant();
            new = new->next;
        }
        i++;
    }
    new = begin;
    return new;
}

reactant_t *manage_reactant(char *str)
{
    reactant_t *reactant;
    char *check = NULL;
    char **tab = NULL;

    if ((check = strstr(str, "listOfReactants")) == NULL)
        return NULL;
    else {
        tab = my_str_to_word_array_synthesis(check);
        reactant = find_info_reactant(tab);
    }
    return reactant;
}