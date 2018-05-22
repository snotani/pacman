#include <ncurses.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define ROWS 25
#define COLUMNS 29


int main(int argc, char *argv[])
{	
	WINDOW *scoreboard;
	//WINDOW 
	int pacmany = 14, pacmanx = 13;
	int height = 10, width = 20;
	int scoreboardy = 0, scoreboardx = 50, score = 0;
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
	scoreboard = newwin(height, width, scoreboardy, scoreboardx);
	box(scoreboard, 0, 0);
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
		
		if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP || key == KEY_DOWN){
			mvwprintw(scoreboard, 1, 1, "Score = %d", score);
			mvwprintw(scoreboard, 1, 1, "Score = %d", score);
			wrefresh(scoreboard);
		}	
				
		switch(key)
		{
			case KEY_LEFT:
					
					if(maze[pacmany][pacmanx-1] != '#')
					{
						if(maze[pacmany][pacmanx-1] == '.')
						{
							score = score + 10; //add 10 points each time it collects a pill
						}
						
						if(maze[pacmany][pacmanx-1] == 'O')
						{
							score = score + 50; //adds 50 points for the power pill
						}
						
						maze[pacmany][pacmanx] = ' ';
						mvaddch(pacmany,pacmanx,' ');
						pacmanx--;
						mvaddch(pacmany, pacmanx, '>');
						move(pacmany, pacmanx);
						refresh();
					}
					break;
			
			case KEY_RIGHT:
					
					if(maze[pacmany][pacmanx+1] != '#')
					{
						if(maze[pacmany][pacmanx+1] == '.')
						{
							score = score + 10; //add 10 points each time it collects a pill
						}
						
						if(maze[pacmany][pacmanx-1] == 'O')
						{
							score = score + 50; //adds 50 points for the power pill
						}
						
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
						if(maze[pacmany-1][pacmanx] == '.')
						{
							score = score + 10; //add 10 points each time it collects a pill
						}
						
						if(maze[pacmany][pacmanx-1] == 'O')
						{
							score = score + 50; //adds 50 points for the power pill
						}
						
						maze[pacmany][pacmanx] = ' ';
						mvaddch(pacmany,pacmanx,' ');
						pacmany--;
						mvaddch(pacmany, pacmanx, 'V');
						move(pacmany, pacmanx);
						refresh();
					}
					break;
					
			case KEY_DOWN:
					
					if(maze[pacmany+1][pacmanx] != '#' && maze[pacmany+1][pacmanx] != '-')
					{
						if(maze[pacmany+1][pacmanx] == '.')
						{
							score = score + 10; //add 10 points each time it collects a pill
						}
						
						if(maze[pacmany][pacmanx-1] == 'O')
						{
							score = score + 50; //adds 50 points for the power pill
						}
						
						maze[pacmany][pacmanx] = ' ';
						mvaddch(pacmany,pacmanx,' ');
						pacmany++;
						mvaddch(pacmany, pacmanx, ACS_UARROW);
						move(pacmany, pacmanx);
						refresh();
					}
					break;
					
		}
		
		if(score == 2150){
			
			
		}
	
	}
	
	endwin();			/* End curses mode		  */

	return 0;
}

