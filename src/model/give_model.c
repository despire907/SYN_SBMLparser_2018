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

model_t *init_mod(void)
{
    model_t *new = malloc(sizeof(model_t));

    new->name = NULL;
    new->id = NULL;
    new->next = NULL;

    return new;
}

model_t *find_info_mod(char **str)
{
    model_t *new = init_mod();
    int i = 1;

    while (my_strcmp(str[i], "id")) {
        if (!my_strcmp(str[i], "name")) {
            i++;
            new->name = give_name(str, i);
        }
        i++;
    }
    new->id = str[++i];
    return new;
}

model_t *manage_model(char *str)
{
    model_t *mod;
    char *check = NULL;
    char **tab = NULL;

    if ((check = strstr(str, "model")) == NULL)
        return NULL;
    else {
        tab = my_str_to_word_array_synthesis(check);
        mod = find_info_mod(tab);
    }
    return mod;
}