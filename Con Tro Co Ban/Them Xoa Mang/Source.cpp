#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void NhapMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("\nNhap vao a[%d] = ", i);
		scanf("%d", &a[i]);
		// scanf("%d", &i[a]);
		// scanf("%d", a + i);
		// scanf("%d", i + a);
		// scanf("%d", a++);
	}
}

void XuatMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%4d", a[i]);
		// printf("%4d", *(a + i));
		// printf("%4d", *(a++));
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

int TimMax(int *a, int n)
{
	int Max = a[0];
	for(int i = 1; i < n; i++)
	{
		if(a[i] > Max)
		{
			Max = a[i];
		}
	}
	return Max;
}

int TimMin(int *a, int n)
{
	int *Min; // Khai báo con trỏ

	Min = &a[0]; // cho con trỏ Min trỏ tới ô đầu tiên
	for(int i = 1; i < n; i++)
	{
		if(a[i] < *Min)
		{
			Min = &a[i]; // cho con trỏ Min trỏ tới địa chỉ mới.
		}
	}
	return *Min;
}

int *TimMin_2(int *a, int n)
{
	int *Min; // Khai báo con trỏ

	Min = &a[0];
	for(int i = 1; i < n; i++)
	{
		if(a[i] < *Min)
		{
			Min = &a[i]; // cho con trỏ trỏ tới địa chỉ mới.
		}
	}
	return Min;
}

/* 
int a, b;
HoanVi_1(a, b);

int *c, *d;
HoanVi_1(*c, *d);
*/
void HoanVi_1(int &a, int &b)
{
	int Temp = a;
	a = b;
	b = Temp;
}

/* 
int a, b;
HoanVi_2(&a, &b);

int *c, *d;
HoanVi_2(c, d);
*/
void HoanVi_2(int *a, int *b)
{
	int Temp = *a;
	*a = *b;
	*b = Temp;
}

void SapXepMang(int *a, int n, char phanloai)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			// sắp tăng dần
			if(phanloai == 't' || phanloai == 'T')
			{
				if(a[i] > a[j])
				{
					// HoanVi_1(a[i], a[j]);
					HoanVi_2(&a[i], &a[j]);
				}
			}
			else if(phanloai == 'g' || phanloai == 'G')
			{
				if(a[i] < a[j])
				{
					// HoanVi_1(a[i], a[j]);
					//HoanVi_2(&a[i], &a[j]);
					HoanVi_1(*(a + i), *(a + j));
					//HoanVi_2(a + i, a + j);
				}
			}
		}
	}
}

void ThemPhanTu(int *&a, int &n, int vitrithem, int phantuthem)
{
	realloc(a, (n + 1) * sizeof(int)); // cấp dư ra 1 ô.

	for(int i = n - 1; i >= vitrithem; i--)
	{
		a[i + 1] = a[i];
	}
	a[vitrithem] = phantuthem;
	n++;
}

// Them vao sau cac so chan so 69
void ThemNhieu(int *&a, int &n, int sophantuthem)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] % 2 == 0)
		{
			for(int j = 1; j <= sophantuthem; j++)
			{
				ThemPhanTu(a, n, i + 1, 70);
				i++; // để tránh bị trùng.
			}
			
		}
	}
}

void XoaPhanTu(int *&a, int &n, int vitrixoa)
{
	for(int i = vitrixoa + 1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	realloc(a, (n - 1) * sizeof(int));
	n--;
}

void XoaTatCaSoChan(int *&a, int &n)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] % 2 == 0)
		{
			XoaPhanTu(a, n, i);
			i--; // để lùi lại xét hết được tất cả.
		}
	}
}

int main()
{
	int n;

	do{
		printf("\nNhap vao so luong phan tu n = ");
		scanf("%d", &n);

		if(n < 0)
		{
			printf("\nGia tri n khong hop le. Xin kiem tra lai !");
		}
	}while(n < 0);

	// cấp phát bộ nhớ cho con trỏ.
	//int *a = (int *)malloc(n * sizeof(int));
	//int *a = (int *)calloc(n, sizeof(int));
	int *a = (int *)realloc(NULL, n * sizeof(int));

	NhapMang(a, n);
	XuatMang(a, n);

	int Tong = TinhTong(a, n);
	printf("\nTong = %d", Tong);

	int Max = TimMax(a, n);
	printf("\nMax = %d", Max);

	int Min = TimMin(a, n);
	printf("\nMin = %d", Min);

	int Min_2 = *TimMin_2(a, n);
	printf("\nMin_2 = %d", Min_2);

	int *min = TimMin_2(a, n);
	printf("\nmin = %d", *min);

	SapXepMang(a, n, 't');
	printf("\nSap xep tang dan: ");
	XuatMang(a, n);

	SapXepMang(a, n, 'g');
	printf("\nSap xep giam dan: ");
	XuatMang(a, n);

	printf("\n\n\n");

	/*int vitrithem = 2;
	int phantuthem = 69;
	ThemPhanTu(a, n, vitrithem, phantuthem);
	XuatMang(a, n);

	int vitrixoa = 3;
	XoaPhanTu(a, n, vitrixoa);
	printf("\nMang sau khi xoa la: ");
	XuatMang(a, n);*/

	/*ThemNhieu(a, n, 3);
	printf("\nThem vao dang sau cac so chan so 69 la: ");
	XuatMang(a, n);*/

	XoaTatCaSoChan(a, n);
	printf("\nXoa het cac so chan la: ");
	XuatMang(a, n);

	//printf("\na[5] = %d", a[5]);

	free(a); // giải phóng bộ nhớ.

	getch();
	return 0;
}