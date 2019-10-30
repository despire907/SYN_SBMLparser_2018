/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#ifndef SBML_PARSER_MODEL_H
#define SBML_PARSER_MODEL_H

typedef struct model_s {
    char *name;
    char *id;
    struct model_s *next;
}model_t;

model_t *manage_model(char *str);
model_t *find_info_mod(char **str);
model_t *init_mod(void);

#endif //SBML_PARSER_MODEL_H
