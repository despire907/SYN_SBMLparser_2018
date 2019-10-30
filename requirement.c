/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int alpha_num(char car)
{
    if ((car >= '0' && car <= '9') || (car >= 'a' && car <= 'z') ||
        (car >= 'A' && car <= 'Z'))
        return 1;
    else
        return 0;
}

int count_char(char const *str)
{
    int i = 0;

    while (alpha_num(str[i]) == 1) {
        i++;
    }
    return i;
}

int count_word(char const *str)
{
    int i = 0;
    int k = 0;

    while (str[i] != '\0') {
        if (alpha_num(str[i]) == 0 && alpha_num(str[i - 1]) == 1)
            k++;
        i++;
    }
    return k;
}

char **my_str_to_word_array_synthesis(char const *str)
{
    char **tab = NULL;
    int i = 0;
    int j = 0;
    int k = 0;
    if ((tab = malloc(sizeof(char *) * (count_word(str) + 1))) == NULL)
        return NULL;
    while (str[i] != '\0') {
        if (alpha_num(str[i]) == 0 && alpha_num(str[i - 1]) == 1) {
            i++;
            j++;
            k = 0;
        } else if (alpha_num(str[i]) == 0 && alpha_num(str[i++ - 1]) == 0);
        if ((tab[j] = malloc(sizeof(char) * (count_char(str + i) + 1))) == NULL)
            return NULL;
        while (alpha_num(str[i]) == 1) {
            tab[j][k] = str[i];
            k++;
            i++;
        } tab[j][k] = '\0';
    } tab[j + 1] = NULL;
    return tab;
}