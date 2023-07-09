#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
	int n = 3;
	int *a = new int[n];

	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	
	int *b = new int[n];

	// Copy dữ liệu từ mảng a cũ sang mảng b.
	for(int i = 0; i < n; i++)
	{
		b[i] = a[i]; // Copy từ a sang b.
	}

	a = new int[n + 1]; // Cấp phát lại a là n + 1 phần tử.

	for(int i = 0; i < n; i++)
	{
		a[i] = b[i]; // Gán lại b sang.
	}
	delete[] b;

	a[3] = 4;

	printf("\na[3] lan 1 = %d", a[3]);

	int *c = new int[n];

	for(int i = 0; i < n; i++)
	{
		c[i] = a[i];
	}

	
	
	a = new int[n];

	for(int i = 0; i < n; i++)
	{
		a[i] = c[i];
	}

	delete[] c;

	printf("\na[3] lan 2 = %d", a[3]);
	printf("\na[0] = %d", a[0]);
	printf("\na[1] = %d", a[1]);
	printf("\na[2] = %d", a[2]);

	delete[] a;
	getch();
}