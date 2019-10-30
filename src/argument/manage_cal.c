/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "sbml.h"

void display_tab_prod(char **tab)
{
    int i = 0;

    printf("-> ");
    while (tab[i] != NULL) {
        if (i == 0)
            printf("1 %s ", tab[i]);
        else
            printf("+ 1 %s", tab[i]);
        i++;
    }
}

void pro_display(info_t *info)
{
    prod_t *begin = info->react->prod;
    int i = 0;
    int nb = nb_of_prod(info);
    char **tab = malloc(sizeof(char *) * (nb + 1));

    while (info->react->prod != NULL) {
        tab[i] = malloc(sizeof(char) * (strlen(info->react->prod->species + 1)));
        if ((tab[i] = info->react->prod->species) == NULL)
            return;
        i++;
        info->react->prod = info->react->prod->next;
    }
    tab[nb] = NULL;
    info->react->prod = begin;
    if (tab != NULL) {
        qsort(tab, nb_of_prod(info), sizeof(char *), my_cmp);
        display_tab_prod(tab);
        printf("\n");
    }
}

void display_tab_react(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        if (i == 0)
            printf("1 %s ", tab[i]);
        else
            printf("+ 1 %s ", tab[i]);
        i++;
    }
}

void re_display(info_t *info)
{
    reactant_t *begin = info->react->reactant;
    int i = 0;
    int nb = nb_of_reactant(info);
    char **tab = malloc(sizeof(char *) * (nb + 1));

    while (info->react->reactant != NULL) {
        tab[i] = malloc(sizeof(char) * (strlen(info->react->reactant->species) + 1));
        if ((tab[i] = info->react->reactant->species) == NULL)
            return;
        i++;
        info->react->reactant = info->react->reactant->next;
    }
    info->react->reactant = begin;
    tab[nb] = NULL;
    if (tab != NULL) {
        qsort(tab, nb_of_reactant(info), sizeof(char *), my_cmp);
        display_tab_react(tab);
    }
}

void manage_display_calcul(info_t *info)
{
    react_t *begin = info->react;

    while (info->react != NULL) {
        if (!my_strcmp(info->id, info->react->id)) {
            if (info->react->reactant != NULL)
                re_display(info);
            if (!my_strcmp(info->react->reversible, "true"))
                printf("<");
            if (info->react->prod != NULL)
                pro_display(info);
        }
        info->react = info->react->next;
    }
    info->react = begin;
}