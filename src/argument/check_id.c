/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "sbml.h"

int my_cmp(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}

void display_tab(char **tab, int nb)
{
    int i = 0;

    while (i <= (nb - 1) && tab[i] != NULL) {
        printf("--->%s\n", tab[i]);
        i++;
    }
}

int manage_display_idcomp(info_t *info)
{
    int i = 0;
    size_t nb = how_name(info);
    species_t *begin = info->species;
    char **tab = malloc(sizeof(char *) * (nb + 1));
    if (!my_strcmp(info->id, info->comp->id)) {
        printf("List of species in compartment %s\n", info->id);
        while (info->species != NULL) {
            if (!my_strcmp(info->species->compartment, info->id) &&
            info->species->name != NULL) {
                tab[i] = malloc(sizeof(char) * (strlen(info->species->name) + 1));
                tab[i] = info->species->name;
                i++;
            }
            info->species = info->species->next;
        } tab[nb] = NULL;
        info->species = begin;
        qsort(tab, nb, sizeof(char *), my_cmp);
        display_tab(tab, i);
        return 1;
    }return 0;
}

void manage_display_id_info(info_t *info)
{
    compartment_t *begin = info->comp;
    species_t *start = info->species;
    react_t *deb = info->react;
    while (info->comp != NULL) {
        if (manage_display_idcomp(info) == 1)
            return;
        info->comp = info->comp->next;
    } while (info->species != NULL) {
        if (manage_display_id_species(info) == 1)
            return;
        info->species = info->species->next;
    } while (info->react != NULL) {
        if (manage_display_id_reaction(info) == 1)
            return;
        info->react = info->react->next;
    } info->species = start;
    info->comp = begin;
    if (manage_display_comp(info) == 1)
            return;
    info->react = deb;
    info->comp = begin;
}