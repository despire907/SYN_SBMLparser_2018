/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "sbml.h"

int my_strcmp(char const *s1, char const *s2)
{
    int papa = 0;

    while (s1[papa] && s2[papa] && s1[papa] == s2[papa]) {
        ++papa;
    }
    return (s1[papa] - s2[papa]);
}

compartment_t *init_comp(void)
{
    compartment_t *new = malloc(sizeof(compartment_t));

    new->name = NULL;
    new->id = NULL;
    new->next = NULL;

    return new;
}

int nb_of_name(char **str, int i)
{
    int j = 0;
    int h = 0;

    while (my_strcmp(str[i], "id")) {
        j = 0;
        while (str[i][j] != '\0') {
            j++;
            h++;
        }
        i++;
    }
    return h + i;
}

char *give_name(char **str, int i)
{
    int nb = nb_of_name(str, i);
    char *name = malloc(sizeof(char) * nb + 1);

    name[nb] = '\0';
    memset(name, '\0', nb);
    while (my_strcmp(str[i], "id")) {
        strcat(name, str[i]);
        if (my_strcmp(str[i + 1], "id"))
            strcat(name, " ");
        i++;
    }
    return name;
}

compartment_t *find_info_comp(char **str)
{
    compartment_t *new = init_comp();
    compartment_t *begin = new;
    int i = 1;

    while (my_strcmp(str[i], "/listOfCompartments")) {
        if (!my_strcmp(str[i], "id")) {
            i++;
            new->id = str[i];
        } if (!my_strcmp(str[i], "name")) {
            i++;
            new->name = give_name(str, i);
        } if (!my_strcmp(str[i], "compartment") && new->name != NULL &&
        new->next == NULL) {
            new->next = init_comp();
            new = new->next;
        }
        i++;
    }
    new = begin;
    return new;
}