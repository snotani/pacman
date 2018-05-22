#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define ROWS 25 //rows for the maze
#define COLUMNS 29 //columns for the maze

char maze[ROWS][COLUMNS] = { //the maze for pacman
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
{'#','#','#','#','#','#','.','#','#',' ','#',' ',' ','M',' ',' ',' ','#',' ','#','#','.','#','#','#','#','#','#'},
{' ',' ',' ',' ',' ',' ','.',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','.',' ',' ',' ',' ',' ',' '},
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

int main()
{	
	WINDOW *scoreboard;	//window to display scoreboard
	WINDOW *title;	//window to display the title of the scoreboard
	
	int pacmany = 14, pacmanx = 13; //defines the initial position of the pacman
	int ghosty = 10, ghostx = 13;  //defines the initial position of the ghost
	char prev = ' ';
	int height = 7, width = 20;	//height and width for scoreboard window
	int scoreboardy = 3, scoreboardx = 40; //x and y coordinates for the location of the scoreboard
	int titley = 1, titlex = 40; //title located on top of the scoreboard
	int score = 0, level = 1, lives = 3; //sets the score, level and lives in the scoreboard
	int key; //key presses
	
	initscr();			// Start curses mode 	
	title = newwin(height, width, titley, titlex); //opens window for the scoreboard title
	box(title, 0, 0);  	//sets the title at the start of the window title
	scoreboard = newwin(height, width, scoreboardy, scoreboardx); //opens window for the scoreboard 
	box(scoreboard, 0, 0); //sets the title at the start of the window scoreboard
	curs_set(FALSE);	//dont show cursor
	keypad(stdscr, TRUE); //allows to use the arrow keys
	srand(time(NULL));
	refresh();			//print it on to the real screen 

	for(int i=0; i<ROWS; i++){ 	//nested loops for 2d maze
		for(int j=0; j<COLUMNS; j++){
			printw("%c", maze[i][j]); //print the maze
		}
		printw("\n"); 
	}
	
	move(pacmany,pacmanx); //moves the cursos to the pacman's initial position
	refresh();	//refresh and print on the screen
	
	while((key = getch()) != 'q') //key 'q' to quit the program
	{
		if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP || key == KEY_DOWN){ //checks if any key es pressed (game starts)
			mvwprintw(title, 1, 1, "SCOREBOARD");	//prints the title of the scoreboard
			mvwprintw(scoreboard, 1, 1, "Level = %d", level); //shows the levels of the game in the scoreboard
			mvwprintw(scoreboard, 2, 1, "Lives = %d", lives); //shows the lives remaining in the scoreboard
			mvwprintw(scoreboard, 3, 1, "Score = %d", score); //shows the score of the game in the scoreboard
			wrefresh(title);
			wrefresh(scoreboard);		//refresh the window and print on screen
		}
				
		switch(key)
		{
			case KEY_LEFT:
														 
					if(maze[pacmany][pacmanx-1] != '#') //checks for the wall in the left direction
					{
						if(maze[pacmany][pacmanx-1] == '.') 
						{
							score = score + 10; //add 10 points each time it collects a pill
						}
						
						if(maze[pacmany][pacmanx-1] == 'O')
						{
							score = score + 50; //adds 50 points for the power pill
						}
						
						if(maze[pacmany][pacmanx-1] == 'M') //check the collision for pacman and the ghost and move pacman to initial position
						{
							lives--;		//removes a life if collision with ghost occurs
							maze[pacmany][pacmanx] = ' ';
							mvaddch(pacmany,pacmanx,' ');
							pacmany = 14;
							pacmanx = 13;
							mvaddch(pacmany, pacmanx, '>'); //set pacman to initial place
							move(pacmany, pacmanx);
							refresh();
						}
						
						maze[pacmany][pacmanx] = ' ';	//if there is no wall, it keeps on moving left
						mvaddch(pacmany,pacmanx,' ');
						pacmanx--;
						mvaddch(pacmany, pacmanx, '>');
						move(pacmany, pacmanx);
						refresh();
					}
					break;
			
			case KEY_RIGHT:
					
					if(maze[pacmany][pacmanx+1] != '#') //checks for the wall in the right direction
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
							lives--;			//removes a life if collision with ghost occurs
							maze[pacmany][pacmanx] = ' ';
							mvaddch(pacmany,pacmanx,' ');
							pacmany = 14;
							pacmanx = 13;
							mvaddch(pacmany, pacmanx, '>'); //set pacman to initial place
							move(pacmany, pacmanx);
							refresh();
						}
						
						maze[pacmany][pacmanx] = ' ';	//if there is no wall, it keeps on moving right
						mvaddch(pacmany,pacmanx,' ');
						pacmanx++;
						mvaddch(pacmany, pacmanx, '<');
						move(pacmany, pacmanx);
						refresh();
					}
					break;
			
			case KEY_UP:
					
					if(maze[pacmany-1][pacmanx] != '#') //checks for the wall in the upwards direction
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
							lives--;			//removes a life if collision with ghost occurs
							maze[pacmany][pacmanx] = ' ';
							mvaddch(pacmany,pacmanx,' ');
							pacmany = 14;
							pacmanx = 13;
							mvaddch(pacmany, pacmanx, '>'); //set pacman to initial place
							move(pacmany, pacmanx);
							refresh();
						}
						
						maze[pacmany][pacmanx] = ' ';	//if there is no wall, it keeps on moving up
						mvaddch(pacmany,pacmanx,' ');
						pacmany--;
						mvaddch(pacmany, pacmanx, 'V');
						move(pacmany, pacmanx);
						refresh();
					}
					break;
					
			case KEY_DOWN:
					
					if(maze[pacmany+1][pacmanx] != '#' && maze[pacmany+1][pacmanx] != '-') //checks for the wall and ghost box in the downwards direction
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
							lives--;			//removes a life if collision with ghost occurs
							maze[pacmany][pacmanx] = ' ';
							mvaddch(pacmany,pacmanx,' ');
							pacmany = 14;
							pacmanx = 13;
							mvaddch(pacmany, pacmanx, '>'); //set pacman to initial place
							move(pacmany, pacmanx);
							refresh();
						}
						
						maze[pacmany][pacmanx] = ' ';  //if there is no wall, it keeps on moving down
						mvaddch(pacmany,pacmanx,' ');
						pacmany++;
						mvaddch(pacmany, pacmanx, ACS_UARROW);
						move(pacmany, pacmanx);
						refresh();
					}
					break;
					
		}
		
		for(int turn = 0; turn < 4; turn++){
			
		int randghost = rand() % 4;
					
			switch(randghost){
									
				case 0:
				{	//move left
					if(maze[ghosty][ghostx-1] == '#')
					{
						maze[ghosty][ghostx] = prev;  //if there is no wall, it keeps on moving down
						mvaddch(ghosty,ghostx,prev);
						ghostx--;
						prev = maze[ghosty][ghostx];
						maze[ghosty][ghostx] = 'M';
						mvaddch(ghosty, ghostx, 'M');
						move(ghosty, ghostx);
						refresh();
					}
				}
									
				case 1:
				{	//move right
					if(maze[ghosty][ghostx+1] == '#')
					{
						maze[ghosty][ghostx] = prev;  //if there is no wall, it keeps on moving down
						mvaddch(ghosty,ghostx,prev);
						ghostx--;
						prev = maze[ghosty][ghostx];
						maze[ghosty][ghostx] = 'M';
						mvaddch(ghosty, ghostx, 'M');
						move(ghosty, ghostx);
						refresh();
					}
				}
									
				case 2:
				{	//move up
					if(maze[ghosty-1][ghostx] == '#')
					{
						maze[ghosty][ghostx] = prev;  //if there is no wall, it keeps on moving down
						mvaddch(ghosty,ghostx,prev);
						ghostx--;
						prev = maze[ghosty][ghostx];
						maze[ghosty][ghostx] = 'M';
						mvaddch(ghosty, ghostx, 'M');
						move(ghosty, ghostx);
						refresh();
					}
				}
									
				case 3:
				{	//move down
					if(maze[ghosty+1][ghostx] == '#')
					{
						maze[ghosty][ghostx] = prev;  //if there is no wall, it keeps on moving down
						mvaddch(ghosty,ghostx,prev);
						ghostx--;
						prev = maze[ghosty][ghostx];
						maze[ghosty][ghostx] = 'M';
						mvaddch(ghosty, ghostx, 'M');
						move(ghosty, ghostx);
						refresh();
					}
				}
			}
		}
		
		
		
		if(score == 2300){  //if all the pills are eaten, game is won
			level++;		//goes to next level
			mvwprintw(scoreboard, 4, 1, "Congratulations!");
			mvwprintw(scoreboard, 5, 1, "Next level: %d", level);
			wrefresh(scoreboard);
			//main();
		}
		
		if(lives < 1){		//if lives are over, game over
			mvwprintw(scoreboard, 6, 1, "GAME OVER!");
			mvwprintw(scoreboard, 7, 1, "No lives left!");
			wrefresh(scoreboard);
		}
		
	}
	
	endwin();			// End curses mode		  

	return 0;
}

