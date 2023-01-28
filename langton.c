#include <stdio.h>
#include <stdlib.h>
#include "langton.h"
#include <ncurses.h>

void turn_left(struct ant *ant)
{
    // check for all direections and change them to the right version
    if (ant->direction == UP)
    {
        ant->direction = LEFT;
    }
    if (ant->direction == LEFT)
    {
        ant->direction = DOWN;
    }
    if (ant->direction == DOWN)
    {
        ant->direction = RIGHT;
    }
    else
    {
        ant->direction = UP;
    }
};
void turn_right(struct ant *ant)
{
    if (ant->direction == UP)
    {
        ant->direction = RIGHT;
    }
    if (ant->direction == RIGHT)
    {
        ant->direction = DOWN;
    }
    if (ant->direction == DOWN)
    {
        ant->direction = LEFT;
    }
    else
    {
        ant->direction = UP;
    }
};
void move_forward(struct ant *ant)
{
    if (ant->direction == UP)
    { // check if we have gone past the screens bounds.
        // we don't need to do an else statement as the ++ assigns the y+1 value already
        if (ant->y++ > getmaxy(stdscr))
        {
            ant->y = 0;
        }
    }
    if (ant->direction == DOWN)
    { // to avoid the int going negative we have checked before the --
        if (ant->y == 0)
        {
            ant->y = getmaxy(stdscr);
        }
        else
        {
            ant->y--;
        }
    }
    if (ant->direction == RIGHT)
    {
        if (ant->x++ > getmaxx(stdscr))
        {
            ant->x = 0;
        };
    }
    else
    {
        if (ant->x == 0)
        {
            ant->x = getmaxx(stdscr);
        }
        else
        {
            ant->x--;
        }
    }
};

void apply_rule(enum colour *colour, struct ant *ant)
{

    if (*colour == WHITE)
    {
        turn_right(ant);
        // change the colour of the cells
    }
    if (*colour == BLACK)
    {
        turn_right(ant);
        // change the colour of the cells
    } // make a warning ifthe colour passed is a null pointer or doesn't work
};
void apply_rule_general(enum colour *colour, struct ant *ant, struct rule *rule){};
