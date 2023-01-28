#include <stdio.h>
#include <stdlib.h>
#include "langton.h"
#include <ncurses.h>
void turn_left(struct ant *ant)
{
    switch (ant->direction)
    {
    case UP:
        ant->direction = LEFT;
        break;
    case LEFT:
        ant->direction = DOWN;
        break;
    case DOWN:
        ant->direction = RIGHT;
        break;
    case RIGHT:
        ant->direction = UP;
        break;
    default:
        break;
    }
}

void turn_right(struct ant *ant)
{
    switch (ant->direction)
    {
    case UP:
        ant->direction = RIGHT;
        break;
    case RIGHT:
        ant->direction = DOWN;
        break;
    case DOWN:
        ant->direction = LEFT;
        break;
    case LEFT:
        ant->direction = UP;
        break;
    default:
        break;
    }
};
void move_forward(struct ant *ant)
{
    switch (ant->direction)
    {
    case DOWN:
        if (ant->y++ >= getmaxy(stdscr))
        {
            ant->y = 0;
        }
        break;
    case UP:
        if (ant->y == 0)
        {
            ant->y = getmaxy(stdscr);
        }
        else
        {
            ant->y--;
        }
        break;
    case RIGHT:
        if (ant->x++ > getmaxx(stdscr))
        {
            ant->x = 0;
        };
        break;

    case LEFT:
        if (ant->x == 0)
        {
            ant->x = getmaxx(stdscr);
        }
        else
        {
            ant->x--;
        }
        break;
    default:
        break;
    }
};

void apply_rule(enum colour *colour, struct ant *ant)
{
    switch (*colour)
    {
    case WHITE:
        turn_left(ant);
        *colour = BLACK;
        break;
    case BLACK:
        turn_right(ant);
        *colour = WHITE;
        break;
    default:
        break;
    }
};
void apply_rule_general(enum colour *colour, struct ant *ant, struct rule *rule){
    /*match correspondding colour to rule execute turn*/

};
