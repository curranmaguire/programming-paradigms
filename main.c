#include <stdio.h>
#include <stdlib.h>
#include "langton.h"
#include "visualiser.h"

#include <curses.h>
#include <ncurses.h>

int main(void)
{
    // initialize ant and start the visualisation
    struct ant *ant = (struct ant *)malloc(sizeof(struct ant));

    start_visualisation(ant);

    // main langton loop
    while (1)
    {
        if (not_quit())
        {
            // input of not q continue the simualtion
            visualise_and_advance(ant);
        }
        else
        {
            // input of q so stop
            end_visualisation();
            break;
        }
    }
    free(ant);
    // ncurses ends
}