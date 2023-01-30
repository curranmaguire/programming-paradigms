#include <stdio.h>
#include <stdlib.h>
#include "langton.h"
#include "visualiser.h"
#include <string.h>
#include <curses.h>
#include <ncurses.h>

void basic_ant(void)
{
    // initialize ant and create memory for it.
    struct ant *ant = (struct ant *)malloc(sizeof(struct ant));
    // start visualisation
    start_visualisation(ant);

    // main langton loop runs until q is pressed
    while (1)
    { // not quit checks for the unput of q if there is no q it runs as standard
        if (not_quit())
        {

            visualise_and_advance(ant);
        }
        else
        {
            // input of q so stop
            end_visualisation();
            break;
        }
    }
    free(ant); // free the space used by malloc for ant
    // ncurses ends
};

void n_state_ant(struct rule *rule)
{

    // initialize ant and create memory for it.
    struct ant *ant = malloc(sizeof(struct ant));

    //  start visualisation
    start_visualisation(ant);
    // main langton loop runs until q is pressed
    while (1)
    { // not quit checks for the unput of q if there is no q it runs as standard
        if (not_quit())
        {

            visualise_and_advance(ant);
        }
        else
        {
            // input of q so stop
            end_visualisation();
            break;
        }
    }
    free(ant); // free the space used by malloc for ant
    free(rule);
    // ncurses ends
};

int main(int argc, char *argv[])
{
    // get the arguments from commandline
    if (argc > 2)
    {
        printf("too many arguments input a rule of e.g. LRR ");
        exit(0);
    }
    else if (argc == 2)
    { // run the n state ant
        struct rule *rule = malloc(sizeof(struct rule) + sizeof(strlen(argv[1]) + 1));
        rule->rules = argv[1];
        n_state_ant(rule);
    }
    else if (argc < 2)
    { // run the basic state ant
        basic_ant();
    }
    return 0;
}