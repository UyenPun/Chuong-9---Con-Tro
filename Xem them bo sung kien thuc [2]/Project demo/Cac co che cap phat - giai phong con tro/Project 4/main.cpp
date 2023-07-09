#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
	int n = 3;
	int *a = (int *)realloc(0, n * sizeof(int));

	a[0] = 1;
	a[1] = 2;
	a[2] = 3;

	realloc(a, (n + 1) * sizeof(int)); // Nới rộng cho nó thêm 1 phần tử.

	a[3] = 4;

	printf("\na[3] lan 1 = %d", a[3]);

	realloc(a, n * sizeof(int)); // Co lại 1 phần tử.
	
	printf("\na[3] lan 2 = %d", a[3]);

	free(a); 
	getch();
}