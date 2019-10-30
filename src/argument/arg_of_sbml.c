/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "sbml.h"

void display_help(void)
{
    printf("USAGE\n\t./SBMLparser SBMLfile [-i ID [-e]] [-json]\n"
    "\nDESCRIPTION\n\tSBMLfile\tSBML file\n\t-i ID\t"
    "id of the compartment, reaction or product to be extracted\n\t\t\t"
    "(ignored if uncorrect\n\t-e\tprint the equation if a reaction ID "
    "is given as argument\n\t\t\t(ignored otherwise)\n\t-json\t"
    "transform the file into a JSON file\n");
}

int check_arg(char **av, info_t *info, int i)
{
    if (av[i][0] == '-' && (
            strcmp(av[i], "-i") &&
            strcmp(av[i], "-e") &&
            strcmp(av[i], "-json")
            ))
        return 84;
    if (!my_strcmp(av[i], "-i")) {
        if (av[i + 1] != NULL) {
            i++;
            info->info_i = 1;
            info->id = av[i];
        } else {
            info->info_i = 1;
            info->id = "oui";
        }
    } if (!my_strcmp(av[i], "-e"))
        info->e_option = 1;
    if (!my_strcmp(av[i], "-json"))
        info->json_option = 1;
    return 0;
}

int list_of_arg(char **av)
{
    info_t *info = NULL;
    int i = 2;
    if ((info = init_info(av[1])) == NULL)
        return 84;
    if (av[i] == NULL)
        manage_display(info);
    else {
        while (av[i] != NULL) {
            if (check_arg(av, info, i) == 84)
                return 84;
            i++;
        } if (info->info_i == 1 && info->e_option == 1 && info->json_option
        == 0)
            manage_display_calcul(info);
        else if (info->info_i == 1 && info->e_option == 0 && info->json_option
        == 0)
            manage_display_id_info(info);
    }
    return 0;
}

int id_reactant(info_t *info)
{
    reactant_t *reactant = info->react->reactant;

    while (info->react->reactant != NULL) {
        if (info->react->reactant->species != NULL &&
        !my_strcmp(info->react->reactant->species, info->id)) {
            info->res = info->react->reactant->stoichiometry;
            return 1;
        }
        info->react->reactant = info->react->reactant->next;
    }
    info->react->reactant = reactant;
    return 0;
}

int id_prod(info_t *info)
{
    prod_t *begin = info->react->prod;

    while (info->react->prod != NULL) {
        if (info->react->prod->species != NULL &&
        !my_strcmp(info->react->prod->species, info->id)) {
            info->res = info->react->prod->stoichiometry;
            return 1;
        }
        info->react->prod = info->react->prod->next;
    }
    info->react->prod = begin;
    return 0;
}