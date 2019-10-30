/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "comp.h"
#include "info.h"
#include "sbml.h"

compartment_t *manage_comp(char *str)
{
    compartment_t *comp;
    char *check = NULL;
    char **tab = NULL;

    if ((check = strstr(str, "listOfCompartments")) == NULL)
        return NULL;
    else {
        tab = my_str_to_word_array_synthesis(check);
        comp = find_info_comp(tab);
    }
    return comp;
}

void display_speciesreference(info_t *info)
{
    if (info->react->reactant != NULL || info->react->prod != NULL) {
        printf("speciesReference\n");
        if (info->react->reactant->species != NULL ||
        info->react->prod->species != NULL)
            printf("----->species\n");
        if (info->react->reactant->stoichiometry != NULL ||
        info->react->prod->stoichiometry != NULL)
            printf("----->stoichiometry\n");
    }
}

void manage_display(info_t *info)
{
    display_comp(info);
    display_model(info);
    display_reaction(info);
    display_sbml(info);
    display_species(info);
    if (info->react != NULL)
        display_speciesreference(info);
}