/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "sbml.h"

void free_react(react_t *react)
{
    react_t *tmp = react;

    while (react != NULL) {
        tmp = react->next;
        free(react->compartment);
        free(react->reversible);
        free(react->name);
        free(react->id);
        free_prod(react->prod);
        free_reactant(react->reactant);
        free(react);
        react = tmp;
    }
}

void free_prod(prod_t *prod)
{
    prod_t *tmp = prod;

    while (prod != NULL) {
        tmp = prod->next;
        free(prod->stoichiometry);
        free(prod->species);
        free(prod);
        prod = tmp;
    }
}

void free_reactant(reactant_t *reactant)
{
    reactant_t *tmp = reactant;

    while (reactant != NULL) {
        tmp = reactant->next;
        free(reactant->stoichiometry);
        free(reactant->species);
        free(reactant);
        reactant = tmp;
    }
}