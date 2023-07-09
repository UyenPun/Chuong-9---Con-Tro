#include <stdio.h>
#include <conio.h>

int main()
{
	int a = 5; // Khai báo biến a mang giá trị là 5.
	int *b; // Khai báo con trỏ b.
	b = &a; // Cho con trỏ b trỏ tới biến a.
	
	// Ngoài ra có thể viết gộp như sau: int *b = &a;
	//a--; // Thay đổi giá trị a.
	//(*b)--; // Thay đổi giá trị con trỏ b.

	int *c; // Khai báo con trỏ c.
	c = b; // Cho con trỏ c trỏ tới con trỏ b.
	(*c)--;
	printf("\nGia tri a la: %d", a);
	printf("\nDia chi cua a la: %p", &a);

	printf("\nGia tri cua con tro b la: %d", *b);
	printf("\nDia chi cua con tro b la: %p", &b);
	printf("\nMien gia tri cua con tro b la: %p", b);

	printf("\nGia tri cua con tro c la: %d", *c);
	printf("\nDia chi cua con tro c la: %p", &c);
	printf("\nMien gia tri cua con tro c la: %p", c);
		
	getch();
	return 0;
}