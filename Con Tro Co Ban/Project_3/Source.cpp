#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // thư viện hỗ trợ cấp phát bộ nhớ cho con trỏ.

int main()
{
	int *b; // Khai báo con trỏ

	// Cấp phát bộ nhớ cho con trỏ.
	b = (int *)malloc(sizeof(int));

	*b = 69; // Gán giá trị 69 cho con trỏ b.

	printf("\n*b = %d", *b);

	free(b); // Giải phóng con trỏ.

	// Việc này không biết trước giá trị là bao nhiêu bởi vì nếu như có tiến trình nào khác lấy nó sử dụng thì giá trị cũ mới mất, còn nếu không có tiến trình nào lấy thì giá trị vẫn còn đó.
	printf("\n*b = %d", *b);

	printf("\nDia chi con tro la: %p", &b);

	/*
	int a = 5; // a thuộc STACK
	int *c = &a; // Cho con trỏ c trỏ tới biến a
	free(c); // giải phóng con trỏ c.
	*/

	getch();
	return 0;
}