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

Test(simple_test_i_option_a, test_without_argument, .init=redirect_all_std)
{
    char *tab[] = {"./SBMLparser", "sbml_file/example.sbml", "-i", "Cytosol"};
    sbmlparser(4, tab);
    fflush(stdout);
    cr_assert_stdout_eq_str("List of species in compartment Cytosol\n"
                            "--->Adenosine diphosphate\n"
                            "--->Adenosine triphosphate\n"
                            "--->Alpha -D-Glucose\n"
                            "--->Glucose 6-phosphate\n");
}

Test(simple_test_i_option_b, test_without_argument, .init=redirect_all_std)
{
    char *tab[] = {"./SBMLparser", "sbml_file/example.sbml", "-i", "Reaction1241"};
    sbmlparser(4, tab);
    fflush(stdout);
    cr_assert_stdout_eq_str("List of reactants of reaction Reaction1241\n"
                            "--->Compound1034\n"
                            "--->Compound983\n"
                            "List of products of reaction Reaction1241\n"
                            "--->Compound414\n"
                            "--->Compound644\n");
}

Test(simple_test_i_option_c, test_without_argument, .init=redirect_all_std)
{
    char *tab[] = {"./SBMLparser", "sbml_file/example.sbml", "-i", "Compound414"};
    sbmlparser(4, tab);
    fflush(stdout);
    cr_assert_stdout_eq_str("List of reactions consuming species Compound414"
                            " (quantities)\n--->Reaction1241 (1)\n");
}