//Write a program that opens a file named my_file.txt on write mode and write 100 into that file
#include <stdio.h>
#define VALUE 100

int main(){
	FILE *fp;
	int val = VALUE;
	fp = fopen("my_file.txt", "w");
	fprintf(fp, "%d", val);
	return 0;
}
