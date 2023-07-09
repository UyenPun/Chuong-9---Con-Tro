#include <stdio.h>
#include <conio.h>

int main()
{
	int a = 5;
	int *b = &a;

	delete b; // Lỗi do đang giải phóng vùng nhớ Stack.

	getch();
	return 0;
}