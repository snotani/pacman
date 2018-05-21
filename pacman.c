#include <ncurses.h>

WINDOW *create_newwin(int height, int width, int starty, int startx);

int main(int argc, char *argv[])
{	
	WINDOW *my_win;
	int starty= 0, startx = 0;
	int height = 5, width = 10;

	initscr();			/* Start curses mode 		  */
	cbreak();
	noecho();			// no keypresses
	curs_set(FALSE);	// dont show cursor
	keypad(stdscr, TRUE);
	
	my_win = create_newwin(height, width, starty, startx);
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */

	return 0;
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters 
					 * for the vertical and horizontal
					 * lines			*/
	
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}