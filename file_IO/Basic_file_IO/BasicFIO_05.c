/*Create a text file on your computer and write a paragraph about internet in that file.
Then write a program which will open that file and print the whole paragraph into console*/
#include <stdio.h>
#define MAX_SIZE 10000
int main(){
	char par[MAX_SIZE];
	FILE *file;
	file = fopen("paragraph.txt", "r");
	while(fgets(par, MAX_SIZE, file)){
		printf("%s", par);
	}
	printf("\n");
}
