/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "sbml.h"

void display_comp(info_t *info)
{
    if (info->comp != NULL) {
        printf("compartment\n");
        if (info->comp->id != NULL)
            printf("----->id\n");
        if (info->comp->name != NULL)
            printf("----->name\n");
    }
}

void display_model(info_t *info)
{
    if (info->mod != NULL) {
        printf("model\n");
        if (info->mod->id != NULL)
            printf("----->id\n");
        if (info->mod->name != NULL)
            printf("----->name\n");
    }
}

void display_reaction(info_t *info)
{
    if (info->react != NULL) {
        printf("reaction\n");
        if (info->react->compartment != NULL)
            printf("----->compartment\n");
        if (info->react->id != NULL)
            printf("----->id\n");
        if (info->react->name != NULL)
            printf("----->name\n");
        if (info->react->reversible != NULL)
            printf("----->reversible\n");
    }
}

void display_sbml(info_t *info)
{
    if (info->sbml != NULL) {
        printf("sbml\n");
        if (info->sbml->level != NULL)
            printf("----->level\n");
        if (info->sbml->version != NULL)
            printf("----->version\n");
        if (info->sbml->xmlns != NULL)
            printf("----->xmlns\n");
    }
}

void display_species(info_t *info)
{
    if (info->species != NULL) {
        printf("species\n");
        if (info->species->compartment != NULL)
            printf("----->compartment\n");
        if (info->species->id != NULL)
            printf("----->id\n");
        if (info->species->name != NULL)
            printf("----->name\n");
    }
}