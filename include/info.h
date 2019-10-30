/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#ifndef SBML_PARSER_INFO_H
#define SBML_PARSER_INFO_H

#include "sbml.h"

typedef struct info_s {
    char *str;
    char *id;
    char *res;
    char **tab;
    int info_i;
    int e_option;
    int json_option;
    compartment_t *comp;
    model_t *mod;
    sbml_t *sbml;
    species_t *species;
    react_t *react;
}info_t;

info_t *new_info(char *str, char **tab);
char *concat_tab(char **tab, char *path);
info_t *init_info(char *str);
void display_species(info_t *info);
void display_sbml(info_t *info);
void display_reaction(info_t *info);
void display_model(info_t *info);
void display_comp(info_t *info);
void display_speciesreference(info_t *info);
void manage_display(info_t *info);
void display_help(void);
void manage_display_id_info(info_t *info);
int manage_display_idcomp(info_t *info);
void display_tab(char **tab, int nb);
size_t how_max_name(char **tab);
int my_cmp(const void *p1, const void *p2);
size_t how_name(info_t *info);
void manage_display_calcul(info_t *info);
int manage_display_id_species(info_t *info);
int manage_display_id_reaction(info_t *info);
int id_prod(info_t *info);
int id_reactant(info_t *info);
int manage_display_comp(info_t *info);
size_t how_name_max(info_t *info);
int nb_of_prod(info_t *info);
int nb_of_reactant(info_t *info);
void free_info(info_t *info);

#endif //SBML_PARSER_INFO_H
