#include <stdlib.h>
#include <stdio.h>


int main(){

	char readstring[128];
	int readint;

	fgets(readstring, 128, stdin);
	readint = atoi(readstring);
	printf("%d",readint);
}
