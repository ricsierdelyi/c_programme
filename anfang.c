#include <stdio.h>

int main (int argc, char **argv){
	int *y;
	int c;
	int x = 15;
	y = &x;
	c = *y;
	printf ("This is the value behind y: %d \n This is c: %d\n This is the adress from x: %p %p\n", *y,c, y, &x);
}
