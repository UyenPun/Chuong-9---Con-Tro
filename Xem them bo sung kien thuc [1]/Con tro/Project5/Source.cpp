#include <iostream>
using namespace std;

// Dùng tham chiếu.
void CapPhatCach1(int *&x)
{
	x = new int;
}

// Đẩy lên 1 mức cao hơn, tức là con trỏ cấp 2.
void CapPhatCach2(int **x)
{
	*x = new int;
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
	cout << "\nNhap vao a = ";
	cin >> *a;

	cout << "\nNhap vao b = ";
	cin >> *b;

	int Min = TimMin(a, b);
	int *Max = TimMax(a, b);
	int Max1 = *TimMax(a, b);
	cout << "\nMin = " << Min << " & Max = " << *Max << " & Max1 = " << Max1;
	
	// Giải phóng con trỏ.
	delete a;
	delete b;


	system("pause");
	return 0;
}