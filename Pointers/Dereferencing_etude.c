#include <stdio.h>
#include <stdlib.h>
#define GRID_SIZE 10
int **grid;
//main function
int main(){
	grid = (int**)malloc(GRID_SIZE*sizeof(int*));
	for(int i = 0; i < GRID_SIZE; i++){
		grid[i] = (int*)malloc(GRID_SIZE*sizeof(int));
	}
	for(int i = 0; i < GRID_SIZE; i++){
		for(int j = 0; j < GRID_SIZE; j++){
			grid[i][j] = i + j;
		}		
	}
	
	for(int i = 0; i < GRID_SIZE; i++){
		for(int j = 0; j < GRID_SIZE; j++){
			printf("%2d ", grid[i][j]);
		}
		printf("\n");
	}
	//dereferencing etude
	//all expressions equal to first row, second column;
	int num;
	//dereferencing rows and columns with *
	num = *(*(grid + 1) + 2);
	printf("%d\n", num);
	//dereferencing rows with * and colums with []
	num = (*(grid + 1))[2];
	printf("%d\n", num);
	//dereferencing rows with [] and columns with *
	num = *(grid[1] + 2);
	printf("%d\n", num);
	//dereferencing rows and columns with []
	num = grid[1][2];
	printf("%d\n", num);
	return 0;
}
