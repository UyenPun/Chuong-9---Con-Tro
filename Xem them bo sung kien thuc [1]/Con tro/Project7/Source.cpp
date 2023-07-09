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

int TinhTong(int *a, int n)
{
	int Tong = 0;

	for(int i = 0; i < n; i++)
	{
		Tong += a[i];
	}
	return Tong;
}

int main()
{
	int n;

	do{
		printf("\nNhap vao n = ");
		scanf("%d", &n);

		if(n < 0)
		{
			printf("\nSo luong phan tu khong hop le. Xin kiem tra lai !");
		}
	}while(n < 0);

	int *a = (int *)calloc(n, sizeof(int*)); // Cấp phát.
	
	NhapMang(a, n);
	XuatMang(a, n);

	int Tong = TinhTong(a, n);
	printf("\nTong = %d", Tong);

	free(a); // Giải phóng con trỏ.
	getch();
	return 0;
}