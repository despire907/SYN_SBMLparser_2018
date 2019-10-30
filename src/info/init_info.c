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

char *concat_tab(char **tab, char *path)
{
    struct stat sts;
    stat(path, &sts);
    char *res = malloc(sizeof(char) * (sts.st_size + 1));
    int i = 0;

    res[sts.st_size] = '\0';
    memset(res, '\0', sts.st_size);
    if (tab == NULL)
        return NULL;
    while (tab[i] != NULL) {
        strcat(res, tab[i]);
        if (tab[i + 1] != NULL)
            strcat(res, " ");
        i++;
    }
    return res;
}

info_t *new_info(char *str, char **tab)
{
    info_t *new = malloc(sizeof(info_t));

    new->str = str;
    new->id = NULL;
    new->res = NULL;
    new->tab = tab;
    new->e_option = 0;
    new->json_option = 0;
    new->info_i = 0;
    new->comp = manage_comp(str);
    new->mod = manage_model(str);
    new->sbml = manage_sbml(str);
    new->species = manage_species(str);
    new->react = manage_reaction(str);

    return new;
}

info_t *init_info(char *str)
{
    char **tab = NULL;
    if ((tab = get_file(str)) == NULL)
        return NULL;
    char *ptr = concat_tab(tab, str);
    info_t *new = new_info(ptr, tab);

    return new;
}