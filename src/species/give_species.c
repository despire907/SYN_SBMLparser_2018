/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "sbml.h"

species_t *init_species(void)
{
    species_t *new = malloc(sizeof(species_t));

    new->compartment = NULL;
    new->name = NULL;
    new->id = NULL;
    new->next = NULL;

    return new;
}

species_t *find_info_species(char **str)
{
    species_t *new = init_species();
    species_t *begin = new;
    int i = 1;
    while (my_strcmp(str[i], "/listOfSpecies")) {
        if (!my_strcmp(str[i], "compartment")) {
            i++;
            new->compartment = str[i];
        } if (!strcmp(str[i], "name")) {
            i++;
            new->name = give_name(str, i);
        } if (!my_strcmp(str[i], "id")) {
            i++;
            new->id = str[i];
        } if (!my_strcmp(str[i], "species") && new->name != NULL &&
        new->next == NULL) {
            new->next = init_species();
            new = new->next;
        } i++;
    } new = begin;
    return new;
}

species_t *manage_species(char *str)
{
    species_t *species;
    char *check = NULL;
    char **tab = NULL;

    if ((check = strstr(str, "listOfSpecies")) == NULL)
        return NULL;
    else {
        tab = my_str_to_word_array_synthesis(check);
        species = find_info_species(tab);
    }
    return species;
}