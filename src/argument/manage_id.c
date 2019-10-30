/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "sbml.h"

int manage_display_id_species(info_t *info)
{
    react_t *begin = info->react;

    if (!my_strcmp(info->id, info->species->id)) {
        printf("List of reactions consuming species %s (quantities)\n",
                info->id);
        while (info->react != NULL) {
            if (id_reactant(info) == 1) {
                printf("--->%s (%s)\n", info->react->id, info->res);
                return 1;
            } else if (id_prod(info) == 1) {
                printf("--->%s (%s)\n", info->react->id, info->res);
                return 1;
            }
            info->react = info->react->next;
        }
        info->react = begin;
    }
    return 0;
}

int nb_name(species_t *species)
{
    int i = 0;
    species_t *begin = species;

    while (species != NULL) {
        i++;
        species = species->next;
    }
    species = begin;
    return i;
}

int manage_display_comp(info_t *info)
{
    int i = 0;
    size_t nb = nb_name(info->species);
    species_t *begin = info->species;
    char **tab = malloc(sizeof(char *) * (nb + 1));

    printf("List of species\n");
    while (info->species != NULL && i < (int)nb)  {
        tab[i] = malloc(sizeof(char) * (strlen(info->species->name) + 1));
        tab[i] = info->species->name;
        i++;
        info->species = info->species->next;
    }
    info->species = begin;
    tab[nb] = NULL;
    qsort(tab, nb, sizeof(char *), my_cmp);
    display_tab(tab, i);
    return 1;
}

void free_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        tab[i] = NULL;
    }
    free(tab);
}