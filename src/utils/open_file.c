/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "sbml.h"

FILE *open_file(char const *filepath)
{
    FILE *stream;

    if (!filepath)
        return NULL;
    stream = fopen(filepath, "r");
    if (!(stream))
        return NULL;
    return (stream);
}

char *get_line(void)
{
    __ssize_t check = 0;
    char *buf = NULL;
    size_t buf_size = 0;

    if ((check = getline(&buf, &buf_size, stdin)) == 0)
        return NULL;
    if (check == -1) {
        free(buf);
        return NULL;
    }
    return buf;
}

char *get_file(void)
{
    char *str = NULL;
    char *res = malloc(sizeof(char));
    size_t i = 0;

    while ((str = get_line()) != NULL) {
        res = realloc(res, i + strlen(str));
        i = i + strlen(str);
        strcat(res, str);
        free(str);
    }
    return res;
}