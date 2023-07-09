#include <stdio.h>
#include <conio.h>

int main()
{
	float a = 5.5;
	void *b; // Khai báo con trỏ vô kiểu.
	b = &a; // Cho con trỏ b trỏ tới biến a.

	// Ngoài ra có thể viết gộp như sau: int *b = &a;
	//a--; // Thay đổi giá trị a.
	(*(float *)b)--; // Thay đổi giá trị con trỏ b.
	printf("\nGia tri a la: %f", a);
	printf("\nDia chi cua a la: %p", &a);

	printf("\nGia tri cua con tro b la: %f", *(float *)b);
	printf("\nDia chi cua con tro b la: %p", &b);
	printf("\nMien gia tri cua con tro b la: %p", b);

	getch();
	return 0;
}