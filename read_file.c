#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	FILE *myFileHandle;
	
	myFileHandle = fopen("maze.txt", "r");
	
	if(myFileHandle != NULL) {
	
		char maze[25][29];
		
		//while(fgets(maze, 30, myFileHandle) != NULL)
			//printf("Line read is: %s", maze);
			
			
		for (int i=0; i<25; i++){
			for (int j=0; j<29; j++){
			
				maze[i][j] = 0;				//initialize 2d array called "map" (Part 1)
			
				fscanf(myFileHandle,"%c", &maze[i][j]);	//scan 2d array

				printf("%c", maze[i][j]);	
			}
		}
		fclose(myFileHandle);
	}

}