#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Dùng tham chiếu.
void CapPhatCach1(int *&x)
{
	x = (int *)realloc(0, sizeof(int *));
}

// Đẩy lên 1 mức cao hơn, tức là con trỏ cấp 2.
void CapPhatCach2(int **x)
{
	*x = (int *)realloc(0, sizeof(int *));
}

// Hàm nhận vào 2 tham số là 2 con trỏ, trả về 1 giá trị là Min.
int TimMin(int *a, int *b)
{
	return *a < *b ? *a : *b;
}

// Hàm nhận vào tham số là 2 con trỏ và trả về 1 con trỏ chứa giá trị lớn nhất.
int* TimMax(int *a, int *b)
{
	return *a > *b ? a : b;
}

int main()
{
	int *a, *b; // Khai báo 2 con trỏ a, b.
	
	// Cấp phát cơ chế malloc
	//a = (int *)malloc(sizeof(int *)); // Cấp phát con trỏ.
	//b = (int *)malloc(sizeof(int *)); // Cấp phát con trỏ.

	// Cấp phát cơ chế calloc
	//a = (int *)calloc(1, sizeof(int *)); // Cấp phát con trỏ.
	//b = (int *)calloc(1, sizeof(int *)); // Cấp phát con trỏ.

	// Cấp phát cơ chế realloc
	//a = (int *)realloc(0, sizeof(int *));
	//b = (int *)realloc(0, sizeof(int *));
	CapPhatCach1(a);
	CapPhatCach2(&b);
	printf("\nNhap vao a = ");
	scanf("%d", a);

	printf("\nNhap vao b = ");
	scanf("%d", b);

	int Min = TimMin(a, b);
	int *Max = TimMax(a, b);
	int Max1 = *TimMax(a, b);
	printf("\nMin = %d & Max = %d & Max1 = %d", Min, *Max, Max1);

	// Giải phóng con trỏ.
	free(a); 
	free(b);


	getch();
	return 0;
}