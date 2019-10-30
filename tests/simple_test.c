/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "sbml.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

int sbmlparser(int ac, char **av)
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

Test(display_help, help, .init=redirect_all_std)
{
    char *tab[] = {"./SBMLparser", "-h"};
    sbmlparser(2, tab);
    fflush(stdout);
    cr_assert_stdout_eq_str("USAGE\n\t./SBMLparser SBMLfile [-i ID [-e]] [-json]\n"
    "\nDESCRIPTION\n\tSBMLfile\tSBML file\n\t-i ID\t"
    "id of the compartment, reaction or product to be extracted\n\t\t\t"
    "(ignored if uncorrect\n\t-e\tprint the equation if a reaction ID "
    "is given as argument\n\t\t\t(ignored otherwise)\n\t-json\t"
    "transform the file into a JSON file\n");
}

Test(simple_test, test_without_argument, .init=redirect_all_std)
{
    char *tab[] = {"./SBMLparser", "sbml_file/example.sbml"};
    sbmlparser(2, tab);
    fflush(stdout);
    cr_assert_stdout_eq_str("compartment\n----->id\n----->name\nmodel\n"
    "----->id\n----->name\nreaction\n----->id\n----->name\n----->reversible\n"
    "sbml\n----->level\n----->version\n----->xmlns\nspecies\n"
    "----->compartment\n----->id\n----->name\nspeciesReference\n"
    "----->species\n----->stoichiometry\n");
}

Test(simple_test_bis, test_without_argument, .init=redirect_all_std)
{
    char *tab[] = {"./SBMLparser", "sbml_file/test2.sbml"};
    sbmlparser(2, tab);
    fflush(stdout);
    cr_assert_stdout_eq_str("sbml\n----->level\n----->version\n----->xmlns\n");
}