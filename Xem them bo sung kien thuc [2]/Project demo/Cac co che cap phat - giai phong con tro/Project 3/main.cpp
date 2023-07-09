#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void NhapMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("\nNhap vao a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void XuatMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%4d", a[i]);
	}
}

void main()
{
	int n;

	do{
		printf("\nNhap vao so luong phan tu cua mang: ");
		scanf("%d", &n);

		if(n < 0)
		{
			printf("\nSo luong phai >= 0. Xin kiem tra lai !");
		}
	}while(n < 0);

	//int *a = (int *)calloc(n, sizeof(int)); // Cấp phát bộ nhớ cần sử dụng.
	int *a = (int *)realloc(0, n * sizeof(int));

	//NhapMang(a, n);
	XuatMang(a, n);

	free(a); // Giải phóng vùng nhớ.

	getch();
}