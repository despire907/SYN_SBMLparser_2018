/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "sbml.h"

int main(int ac, char **av)
{
    (void)ac;
    int i = 0;

    while (av[i] != NULL) {
        if (!my_strcmp(av[i], "-json"))
            return 0;
        i++;
    }
    if (av[1] != NULL && !my_strcmp(av[1], "-h")) {
        display_help();
        return 0;
    } else if (av[1] == NULL || av[1][1] == '-')
        return 84;
    if (list_of_arg(av) == 84)
        return 84;

    return 0;
}