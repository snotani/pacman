#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define ROWS 25
#define COLUMNS 29

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
{'#','#','#','#','#','#','.','#','#',' ','#',' ',' ','M','M',' ',' ','#',' ','#','#','.','#','#','#','#','#','#'},
{' ',' ',' ',' ',' ',' ','.',' ',' ',' ','#',' ',' ','M','M',' ',' ','#',' ',' ',' ','.',' ',' ',' ',' ',' ',' '},
{'#','#','#','#','#','#','.','#','#',' ','#',' ',' ',' ',' ',' ',' ','#',' ','#','#','.','#','#','#','#','#','#'},
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



/*void ghostmover(int ghosty, int ghostx)
{	
	srand(time(NULL));
	int randghost = rand() % 4;
				
	if(randghost == 0){
		while(1){
			if(maze[ghosty][ghostx-1] == '#')
			{
				ghostmover(ghosty, ghostx);
			}
		}
	}
				
	if(randghost == 1){
		while(1){
			if(maze[ghosty][ghostx+1] == '#')
			{
				ghostmover(ghosty, ghostx);
			}
		}
	}
				
	if(randghost == 2){
		while(1){
			if(maze[ghosty-1][ghostx] == '#')
			{
				ghostmover(ghosty, ghostx);
			}
		}
	}
				
	if(randghost == 3){
		while(1){
			if(maze[ghosty+1][ghostx] == '#')
			{
				ghostmover(ghosty, ghostx);
			}
		}
	}
}*/


int main()
{	
	WINDOW *scoreboard;	
	WINDOW *title;
	int pacmany = 14, pacmanx = 13;
	int ghosty = 10, ghostx = 13; 
	int height = 7, width = 20;
	int scoreboardy = 3, scoreboardx = 40;
	int titley = 1, titlex = 40;
	int score = 0, level = 1, lives = 3;
	int key;
	
	initscr();			/* Start curses mode 		  */
	title = newwin(height, width, titley, titlex);
	box(title, 0, 0);
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
			mvwprintw(title, 1, 1, "SCOREBOARD");
			mvwprintw(scoreboard, 1, 1, "Level = %d", level);
			mvwprintw(scoreboard, 2, 1, "Lives = %d", lives);
			mvwprintw(scoreboard, 3, 1, "Score = %d", score);
			wrefresh(title);
			wrefresh(scoreboard);
		
			//ghostmover(ghosty, ghostx);
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
						
						if(maze[pacmany][pacmanx-1] == 'M')
						{
							lives--;
							maze[pacmany][pacmanx] = ' ';
							mvaddch(pacmany,pacmanx,' ');
							pacmany = 14;
							pacmanx = 13;
							mvaddch(pacmany, pacmanx, '>');
							move(pacmany, pacmanx);
							refresh();
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
						
						if(maze[pacmany][pacmanx+1] == 'O')
						{
							score = score + 50; //adds 50 points for the power pill
						}
						
						if(maze[pacmany][pacmanx+1] == 'M')
						{
							lives--;
							maze[pacmany][pacmanx] = ' ';
							mvaddch(pacmany,pacmanx,' ');
							pacmany = 14;
							pacmanx = 13;
							mvaddch(pacmany, pacmanx, '>');
							move(pacmany, pacmanx);
							refresh();
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
						
						if(maze[pacmany-1][pacmanx] == 'O')
						{
							score = score + 50; //adds 50 points for the power pill
						}
						
						if(maze[pacmany-1][pacmanx] == 'M')
						{
							lives--;
							maze[pacmany][pacmanx] = ' ';
							mvaddch(pacmany,pacmanx,' ');
							pacmany = 14;
							pacmanx = 13;
							mvaddch(pacmany, pacmanx, '>');
							move(pacmany, pacmanx);
							refresh();
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
						
						if(maze[pacmany+1][pacmanx] == 'O')
						{
							score = score + 50; //adds 50 points for the power pill
						}
						
						if(maze[pacmany+1][pacmanx] == 'M')
						{
							lives--;
							maze[pacmany][pacmanx] = ' ';
							mvaddch(pacmany,pacmanx,' ');
							pacmany = 14;
							pacmanx = 13;
							mvaddch(pacmany, pacmanx, '>');
							move(pacmany, pacmanx);
							refresh();
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
		
		if(score == 2300){
			level++;
			mvwprintw(scoreboard, 4, 1, "Congratulations!");
			mvwprintw(scoreboard, 5, 1, "Next level: %d", level);
			wrefresh(scoreboard);
			
			main();
		}
		
		if(lives < 1){
			mvwprintw(scoreboard, 6, 1, "GAME OVER!");
			mvwprintw(scoreboard, 7, 1, "No lives left!");
			wrefresh(scoreboard);
		}
		
	}
	
	endwin();			/* End curses mode		  */

	return 0;
}

