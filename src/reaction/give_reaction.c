/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "sbml.h"

react_t *init_reaction(char *str)
{
    react_t *new = malloc(sizeof(react_t));

    new->compartment = NULL;
    new->reversible = NULL;
    new->name = NULL;
    new->id = NULL;
    new->prod = manage_prod(str);
    new->reactant = manage_reactant(str);
    new->next = NULL;

    return new;
}

react_t *find_info_reaction(char **str, char *ptr)
{
    react_t *new = init_reaction(ptr);
    int i = 1;

    while (my_strcmp(str[i], "id")) {
        if (!my_strcmp(str[i], "compartment")) {
            i++;
            new->compartment = str[i];
        }
        if (!my_strcmp(str[i], "reversible")) {
            i++;
            new->reversible = str[i];
        } if (!my_strcmp(str[i], "name")) {
            i++;
            new->name = str[i];
        }
        i++;
    }
    new->id = str[++i];
    return new;
}

react_t *manage_reaction(char *str)
{
    react_t *react;
    char *check = NULL;
    char **tab = NULL;

    if ((check = strstr(str, "listOfReactions")) == NULL)
        return NULL;
    else {
        tab = my_str_to_word_array_synthesis(check);
        react = find_info_reaction(tab, str);
    }
    return react;
}