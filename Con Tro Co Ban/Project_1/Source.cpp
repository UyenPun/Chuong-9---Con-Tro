#include <stdio.h>
#include <conio.h>

int main()
{
	int a = 10; // a là 1 biến bình thường.
	int *b; // b là con trỏ

	b = &a; // con trỏ trỏ tới 1 biến bình thường.

	printf("\nGia tri cua a la: %d", a);
	printf("\nDia chi cua a la: %p", &a);

	printf("\nGia tri cua con tro b la: %d", *b);
	printf("\nMien gia tri cua con tro b la: %p", b);
	printf("\nDia chi thuc su cua con tro b la: %p", &b);

	//(*b) = 5; // lấy giá trị con trỏ b tăng lên 5 lần.
	//printf("\na = %d", a);

	int *c; // Khai báo con trỏ c
	c = b; // con trỏ trỏ tới 1 con trỏ khác

	(*c) = 69;
	
	printf("\nGia tri cua con tro c la: %d", *c);
	printf("\nMien gia tri cua con tro c la: %p", c);
	printf("\nDia chi thuc su cua con tro c la: %p", &c);

	printf("\na = %d", a);
	printf("\n*b = %d", *b);

	/*
	int *d; // nằm bơ vơ giữa ngã 4
	*d = 5; // Sẽ bị sai cho d chưa có bộ nhớ cấp hoặc chưa trỏ tới vùng nhớ nào cả.
	*/

	double *z;
	printf("\nSizeof(z) = %d", sizeof(z));

	getch();
	return 0;
}