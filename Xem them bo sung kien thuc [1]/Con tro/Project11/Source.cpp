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

void ThemPhanTu(int *&a, int &n, int ViTriThem, int PhanTuThem)
{
	realloc(a, (n + 1) * sizeof(int *)); // Gia tăng bộ nhớ thêm 1 ô.
	for(int i = n; i >= ViTriThem + 1; i--)
	{
		a[i] = a[i - 1];
	}
	a[ViTriThem] = PhanTuThem;
	n++; // Tăng số lượng phần tử lên.
}

void XoaPhanTu(int *a, int &n, int ViTriXoa)
{
	for(int i = ViTriXoa; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	n--; // Giảm số lượng phần tử xuống.

	realloc(a, n * sizeof(int *)); // giảm đi 1 ô.
}

int main()
{
	int n;

	do{
		printf("\nNhap vao so luong phan tu cua mang: ");
		scanf("%d", &n);

		if(n < 0)
		{
			printf("\nSo luong phan tu khong hop le. Xin kiem tra lai !");
		}
	}while(n < 0);

	int *a; // Khai báo con trỏ.
	a = (int *)malloc(n * sizeof(int *)); // Cấp phát bộ nhớ.

	NhapMang(a, n);
	XuatMang(a, n);

	int ViTriThem, PhanTuThem;

	// Vị trí thêm nằm trong đoạn từ 0 --> n
	do{
		printf("\nNhap vao vi tri can them (%d --> %d): ", 0, n);
		scanf("%d", &ViTriThem);

		if(ViTriThem < 0 || ViTriThem > n)
		{
			printf("\nVi tri them khong hop le. Xin kiem tra lai !");
		}
	}while(ViTriThem < 0 || ViTriThem > n);

	printf("\nNhap vao phan tu can them: ");
	scanf("%d", &PhanTuThem);

	ThemPhanTu(a, n, ViTriThem, PhanTuThem);
	printf("\nMang a sau khi them phan tu %d vao vi tri %d la:\n", PhanTuThem, ViTriThem);

	XuatMang(a, n);

	int ViTriXoa;

	// Vị trí xóa nằm trong đoạn 0 --> n - 1
	do{
		printf("\nNhap vao vi tri xoa (%d --> %d): ", 0, n - 1);
		scanf("%d", &ViTriXoa);

		if(ViTriXoa < 0 || ViTriXoa > n - 1)
		{
			printf("\nVi tri xoa khong hop le. Xin kiem tra lai !");
		}
	}while(ViTriXoa < 0 || ViTriXoa > n - 1);

	XoaPhanTu(a, n, ViTriXoa);
	printf("\nMang a sau khi xoa phan tu tai vi tri %d la:\n", ViTriXoa);

	XuatMang(a, n);

	printf("\na[%d] = %d", n, a[n]);

	free(a); // Giải phóng con trỏ.
	getch();
	return 0;
}