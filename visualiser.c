#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include "visualiser.h"
#define cell_under_ant cell_at(ant->y, ant->x)
cell2 *cells;
extern struct rule *rule;
// this goes to the position in the array of cells assigned by calloc and returns that cell
#define cell_at(x, y) (cells[y * getmaxx(stdscr) + x])

void start_visualisation(struct ant *ant)
{
   setlocale(LC_ALL, "");

   initscr();
   curs_set(FALSE);
   max_x = getmaxx(stdscr);
   max_y = getmaxy(stdscr);
   cells = calloc(max_y * max_x, sizeof(cell2));
   ant->x = max_x / 2;
   ant->y = max_y / 2;
   ant->direction = RIGHT;
}

// return a char from a cell so it can be printed
char *print_cell(cell2 cell)
{
   switch (cell)
   {
   case 0:
      return " ";
      break;

   case 1:
      return "b";
      break;
   case 2:
      return "c";
      break;
   case 3:
      return "d";
      break;
   case 4:
      return "e";
      break;
   case 5:
      return "f";
      break;
   case 6:
      return "g";
      break;
   case 7:
      return "h";
      break;
   case 8:
      return "i";
      break;
   case 9:
      return "j";
      break;
   case 10:
      return "k";
      break;
   case 11:
      return "l";
      break;
   case 12:
      return "m";
      break;
   case 13:
      return "n";
      break;
   case 14:
      return "o";
      break;
   case 15:
      return "p";
      break;
   case 16:
      return "q";
      break;
   case 17:
      return "r";
      break;
   case 18:
      return "s";
      break;
   case 19:
      return "t";
      break;
   case 20:
      return "u";
      break;
   case 21:
      return "v";
      break;
   case 22:
      return "w";
      break;
   case 23:
      return "x";
      break;
   case 24:
      return "y";
      break;
   case 25:
      return "z";
      break;
   case 26:
      return "a";
      break;
   default:
      break;
   }
}

void visualise_and_advance(struct ant *ant)
{
   /* Draw cells and ant */
   for (int y = 0; y < max_y; y++)
   {
      for (int x = 0; x < max_x; x++)
      {
         mvprintw(y, x,
                  ant_is_at(y, x)
                      ? direction_to_s(ant->direction)
                      : print_cell(cell_at(y, x)));
      }
   }
   refresh();

   /* Advance to next step */
   apply_rule_general(&cell_under_ant, ant, rule);
   move_forward(ant);
}

// Check if the user has input "q" to quit
bool not_quit()
{
   return 'q' != getch();
}

void end_visualisation()
{
   free(cells);
   endwin();
}

const char *direction_to_s(enum direction d)
{
   return UP == d ? "^" : DOWN == d ? "v"
                      : LEFT == d   ? "<"
                                    :
                                  /* else */ ">";
}
