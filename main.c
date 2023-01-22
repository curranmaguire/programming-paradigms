#include <stdio.h>

#include <ncurses.h>

int main(void)
{
    initscr();
    noecho();
    cbreak(); // starting the window for ncurses

    // get the screen size
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);

    // create a window for our input
    WINDOW *inputwin = newwin(3, xMax - 12, yMax - 5, 5);
    box(inputwin, 0, 0);
    refresh();
    wrefresh(inputwin);
    // main langton loop
    while (1)
    {

        int c = wgetch(inputwin);
        if (c == 'q')
        {
            // input of q exit the simualtion
            mvwprintw(inputwin, 1, 1, " you pressed q");
            wrefresh(inputwin);
            endwin();
            break;
        }
        else
        {
            // input of not q so move to next instance
            mvwprintw(inputwin, 1, 1, " you pressed a key");
            wrefresh(inputwin);
        }
    }

    // make sure program waits before exiting
    getch();
    endwin();
    // ncurses ends
}