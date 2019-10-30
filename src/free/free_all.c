/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "sbml.h"

void free_info(info_t *info)
{
    free(info->str);
    free(info->id);
    free(info->res);
    free_tab(info->tab);
    free_comp(info->comp);
    free_mod(info->mod);
    free_sbml(info->sbml);
    free_species(info->species);
    free_react(info->react);
}

void free_comp(compartment_t *comp)
{
    compartment_t *tmp = comp;

    while (comp != NULL) {
        tmp = comp->next;
        free(comp->name);
        free(comp->id);
        free(comp);
        comp = tmp;
    }
}

void free_mod(model_t *mod)
{
    model_t *tmp = mod;

    while (mod != NULL) {
        tmp = mod->next;
        free(mod->name);
        free(mod->id);
        free(mod);
        mod = tmp;
    }
}

void free_sbml(sbml_t *sbml)
{
    sbml_t *tmp = sbml;

    while (sbml != NULL) {
        tmp = sbml->next;
        free(sbml->xmlns);
        free(sbml->level);
        free(sbml->version);
        free(sbml);
        sbml = tmp;
    }
}

void free_species(species_t *species)
{
    species_t *tmp = species;

    while (species != NULL) {
        tmp = species->next;
        free(species->compartment);
        free(species->name);
        free(species->id);
        free(species);
        species = tmp;
    }
}