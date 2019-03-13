/*create a text file in your computer and write 1' integers in 10 separate lines. 
Now write a program which will open the file and read the 10 integers. Finally print the average of the ten integers*/
#include <stdio.h>
#define NUM_ELEMENTS 10
//main function
int main(){
	FILE *file;
	int n[NUM_ELEMENTS];
	int sum = 0;
	int i = 0;
	file = fopen("integers.txt", "r");
	while(fscanf(file, "%d", &n[i]) != EOF){
		i++;
	}
	for(i = 0; i < NUM_ELEMENTS; i++){
		sum += n[i];
	}
	printf("%.2f", sum/(double)NUM_ELEMENTS);
	return 0;
}
