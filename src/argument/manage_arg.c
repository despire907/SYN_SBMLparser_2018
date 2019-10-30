/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "sbml.h"

size_t how_name(info_t *info)
{
    int i = 0;
    species_t *begin = info->species;

    while (info->species != NULL) {
        if (!my_strcmp(info->species->compartment, info->id) &&
            info->species->name != NULL)
            i++;
        info->species = info->species->next;
    }
    info->species = begin;

    return i;
}