/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "info.h"
#include "comp.h"
#include "sbml.h"
#include "model.h"

sbml_t *init_sbml(void)
{
    sbml_t *new = malloc(sizeof(sbml_t));

    new->xmlns = NULL;
    new->level = NULL;
    new->version = NULL;
    new->next = NULL;

    return new;
}

sbml_t *find_info_sbml(char **str)
{
    sbml_t *new = init_sbml();
    int i = 1;

    while (my_strcmp(str[i], "version")) {
        if (!my_strcmp(str[i], "xmlns")) {
            i++;
            new->xmlns = str[i];
        } if (!my_strcmp(str[i], "level")) {
            i++;
            new->level = str[i];
        }
        i++;
    }
    new->version = str[++i];
    return new;
}

sbml_t *manage_sbml(char *str)
{
    sbml_t *sbml;
    char *check = NULL;
    char **tab = NULL;

    if ((check = strstr(str, "sbml")) == NULL)
        return NULL;
    else {
        tab = my_str_to_word_array_synthesis(check);
        sbml = find_info_sbml(tab);
    }
    return sbml;
}