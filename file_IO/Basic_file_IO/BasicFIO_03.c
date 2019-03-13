/*write a program which will create a file named my_file03.txt and write "we LOVE" int that file. Then
read the file and print the text of that file into console. Finally, append "our Planet!" with the previous text
of that file and print the whole text again into console*/

#include <stdio.h>

int main(){
	char c;
	FILE *file;
	file = fopen("my_file03.txt", "w");
	fprintf(file, "%s", "we LOVE");
	fclose(file);
	
	file = fopen("my_file03.txt", "r");
	//if there is an error in opening the file, the fopen function returns NULL
	if(file){
		while((c = getc(file)) != EOF){
			putchar(c);
		}
		fclose(file);
	}
	printf("\n");
	
	file = fopen("my_file03.txt", "a");
	fprintf(file, "%s", " our Planet!");
	fclose(file);
	
	file = fopen("my_file03.txt", "r");
	if(file){
		while((c = getc(file)) != EOF){
			putchar(c);
		}
		fclose(file);
	}
	return 0;
}
