/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "sbml.h"

int nb_of_reactant(info_t *info)
{
    reactant_t *begin = info->react->reactant;
    int i = 0;

    while (info->react->reactant != NULL) {
        if (info->react->reactant->species != NULL)
            i++;
        info->react->reactant = info->react->reactant->next;
    }
    info->react->reactant = begin;
    return i;
}

int nb_of_prod(info_t *info)
{
    prod_t *begin = info->react->prod;
    int i = 0;

    while (info->react->prod != NULL) {
        if (info->react->prod->species != NULL)
            i++;
        info->react->prod = info->react->prod->next;
    }
    info->react->prod = begin;

    return i;
}

void reactant_display(info_t *info)
{
    reactant_t *begin = info->react->reactant;
    int i = 0;
    char **tab = malloc(sizeof(char *) * (nb_of_reactant(info) + 1));

    printf("List of reactants of reaction %s\n", info->id);
    while (info->react->reactant != NULL) {
        tab[i] = malloc(sizeof(char) * (strlen(info->react->reactant->species) + 1));
        if ((tab[i] = info->react->reactant->species) == NULL)
            return;
        i++;
        info->react->reactant = info->react->reactant->next;
    }
    tab[i] = NULL;
    info->react->reactant = begin;
    if (tab != NULL) {
        qsort(tab, nb_of_reactant(info), sizeof(char *), my_cmp);
        display_tab(tab, i);
    }
}

void prod_display(info_t *info)
{
    prod_t *begin = info->react->prod;
    int i = 0;
    char **tab = malloc(sizeof(char *) * (nb_of_prod(info) + 1));

    printf("List of products of reaction %s\n", info->id);
    while (info->react->prod != NULL) {
        tab[i] = malloc(sizeof(char) * (strlen(info->react->prod->species) + 1));
        if ((tab[i] = info->react->prod->species) == NULL)
            return;
        i++;
        info->react->prod = info->react->prod->next;
    }
    tab[i] = NULL;
    info->react->prod = begin;
    if (tab != NULL) {
        qsort(tab, nb_of_prod(info), sizeof(char *), my_cmp);
        display_tab(tab, i);
    }
}

int manage_display_id_reaction(info_t *info)
{
    if (!my_strcmp(info->id, info->react->id)) {
        if (info->react->reactant != NULL && info->react->reactant->species !=
        NULL)
            reactant_display(info);
        if (info->react->prod != NULL && info->react->prod->species != NULL)
            prod_display(info);
        return 1;
    }
    return 0;
}