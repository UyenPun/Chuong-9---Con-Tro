#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // cấp phát bộ nhớ cho con trỏ.

void NhapMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("\nNhap vao a[%d] = ", i);
		//scanf("%d", &a[i]);
		//scanf("%d", &i[a]);
		//scanf("%d", a + i); // a + i: Là địa chỉ
		scanf("%d", a++); // a++: Là địa chỉ
	}
}

void XuatMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		//printf("%4d", a[i]);
		//printf("%4d", *(a + i));
		printf("%4d", *(a++));
	}
}


int main()
{
	int n;

	do{
		printf("\nNhap vao n = ");
		scanf("%d", &n);

		if(n < 0)
		{
			printf("\nGia tri n khong hop le. Xin kiem tra lai !");
		}
	}while(n < 0);

	// cấp phát con trỏ mảng
	int *a; // khai báo

	// cấp phát bộ nhớ.
	//a = (int *)malloc(n * sizeof(int));
	//a = (int *)calloc(n, sizeof(int));
	a = (int *)realloc(NULL, n * sizeof(int));

	/*for(int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	}*/

	NhapMang(a, n);
	XuatMang(a, n);

	// gia tăng thêm 1 ô nhớ.
	//realloc(a, (n + 1) * sizeof(int));

	// giảm bớt 1 ô nhớ.
	// realloc(a, (n - 1) * sizeof(int));

	//a[n] = 69;
	//printf("\na[n] = %d", a[n]);

	free(a); // giải phóng bộ nhớ.

	getch();
	return 0;
}