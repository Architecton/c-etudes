//Write a program which will delete all the text from a text file and write "LOVE" on that file
#include <stdio.h>

int main(){
	FILE *fp;
	char *string = "LOVE";
	fp = fopen("my_file02.txt", "w");
	fprintf(fp, "%s", string);
	return 0;
}
