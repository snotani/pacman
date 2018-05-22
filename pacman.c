#include <ncurses.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define ROWS 25
#define COLUMNS 29


int main(int argc, char *argv[])
{	
	////WINDOW *my_win;
	//WINDOW 
	int pacmany= 14, pacmanx = 13;
	int key;
	
	char maze[ROWS][COLUMNS] = {
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','#','#','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','.','#','#','#','#','.','#','#','#','#','#','.','#','#','.','#','#','#','#','#','.','#','#','#','#','.','#'},
{'#','O','#','#','#','#','.','#','#','#','#','#','.','#','#','.','#','#','#','#','#','.','#','#','#','#','O','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','.','#','#','#','#','.','#','#','.','#','#','#','#','#','#','#','#','.','#','#','.','#','#','#','#','.','#'},
{'#','.','.','.','.','.','.','#','#','.','.','.','.','#','#','.','.','.','.','#','#','.','.','.','.','.','.','#'},
{'#','#','#','#','#','#','.','#','#','#','#','#',' ','#','#',' ','#','#','#','#','#','.','#','#','#','#','#','#'},
{' ',' ',' ',' ',' ','#','.','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','.','#',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ','#','.','#','#',' ','#','#','#','-','-','#','#','#',' ','#','#','.','#',' ',' ',' ',' ',' '},
{'#','#','#','#','#','#','.','#','#',' ','#',' ','H','H','H','H',' ','#',' ','#','#','.','#','#','#','#','#','#'},
{' ',' ',' ',' ',' ',' ','.',' ',' ',' ','#',' ','H','H','H','H',' ','#',' ',' ',' ','.',' ',' ',' ',' ',' ',' '},
{'#','#','#','#','#','#','.','#','#',' ','#',' ','H','H','H','H',' ','#',' ','#','#','.','#','#','#','#','#','#'},
{' ',' ',' ',' ',' ','#','.','#','#',' ','#','#','#','#','#','#','#','#',' ','#','#','.','#',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ','#','.','#','#',' ',' ',' ',' ','<',' ',' ',' ',' ',' ','#','#','.','#',' ',' ',' ',' ',' '},
{'#','#','#','#','#','#','.','#','#',' ','#','#','#','#','#','#','#','#',' ','#','#','.','#','#','#','#','#','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','#','#','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','.','#','#','#','#','.','#','#','#','#','#','.','#','#','.','#','#','#','#','#','.','#','#','#','#','.','#'},
{'#','O','.','.','#','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','#','.','.','O','#'},
{'#','#','#','.','#','#','.','#','#','.','#','#','#','#','#','#','#','#','.','#','#','.','#','#','.','#','#','#'},
{'#','.','.','.','.','.','.','#','#','.','.','.','.','#','#','.','.','.','.','#','#','.','.','.','.','.','.','#'},
{'#','.','#','#','#','#','#','#','#','#','#','#','.','#','#','.','#','#','#','#','#','#','#','#','#','#','.','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
};
	

	initscr();			/* Start curses mode 		  */
	//my_win = newwin(height, width, starty, startx);
	//cbreak();
	//noecho();			// no keypresses
	curs_set(FALSE);	// dont show cursor
	keypad(stdscr, TRUE);
	refresh();			/* Print it on to the real screen */
	//getch();			/* Wait for user input */
	for(int i=0; i<ROWS; i++){
		for(int j=0; j<COLUMNS; j++){
			printw("%c", maze[i][j]);
		}
		printw("\n");
	}
	
	move(pacmany,pacmanx);
	refresh();
	
	while((key = getch()) != 'q')
	{
			
		switch(key)
		{
			case KEY_LEFT:
					
					if(maze[pacmany][pacmanx-1] != '#')
					{
						/*if(maze[pacmany][pacmanx-1] == '.')
						{
							score++
						}*/
						
						maze[pacmany][pacmanx] = ' ';
						mvaddch(pacmany,pacmanx,' ');
						pacmanx--;
						mvaddch(pacmany, pacmanx, '<');
						move(pacmany, pacmanx);
						refresh();
					}
					break;
			
			case KEY_RIGHT:
					
					if(maze[pacmany][pacmanx+1] != '#')
					{
						/*if(maze[15][14-1] == '.')
						{
							score++
						}*/
						
						maze[pacmany][pacmanx] = ' ';
						mvaddch(pacmany,pacmanx,' ');
						pacmanx++;
						mvaddch(pacmany, pacmanx, '<');
						move(pacmany, pacmanx);
						refresh();
					}
					break;
			
			case KEY_UP:
					
					if(maze[pacmany-1][pacmanx] != '#')
					{
						/*if(maze[15][14-1] == '.')
						{
							score++
						}*/
						
						maze[pacmany][pacmanx] = ' ';
						mvaddch(pacmany,pacmanx,' ');
						pacmany--;
						mvaddch(pacmany, pacmanx, '<');
						move(pacmany, pacmanx);
						refresh();
					}
					break;
					
			case KEY_DOWN:
					
					if(maze[pacmany+1][pacmanx] != '#')
					{
						/*if(maze[15][14-1] == '.')
						{
							score++
						}*/
						
						maze[pacmany][pacmanx] = ' ';
						mvaddch(pacmany,pacmanx,' ');
						pacmany++;
						mvaddch(pacmany, pacmanx, '<');
						move(pacmany, pacmanx);
						refresh();
					}
					break;
					
		}
	
	}
	
	endwin();			/* End curses mode		  */

	return 0;
}

