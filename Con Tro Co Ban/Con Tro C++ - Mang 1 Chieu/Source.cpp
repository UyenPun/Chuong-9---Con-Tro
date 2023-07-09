#include <iostream>
using namespace std;

void NhapMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "\nNhap vao a[" << i << "] = ";
		// cin >> a[i];
		cin >> *(a + i);
	}
}

void XuatMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		// cout << "   " << a[i];
		cout << "   " << *(a + i);
	}
}

// vừa để gia tăng, vừa giảm bớt ô nhớ.
void REALLOC(int *&a, int OldSize, int NewSize)
{
	// Bước 1: Tạo ra 1 mảng mới là bản sao của mảng cũ rồi đổ dữ liệu từ mảng cũ sang.
	int *tam = new int[OldSize];

	for(int i = 0; i < OldSize; i++)
	{
		tam[i] = a[i];
	}

	// Bước 2: Xóa mảng cũ đi và cấp mới lại.
	delete[] a;
	a = new int[NewSize];

	// Bước 3: Đổ dữ liệu từ mảng tạm sang mảng mới.
	int Min = OldSize < NewSize ? OldSize : NewSize;

	for(int i = 0; i < Min; i++)
	{
		a[i] = tam[i];
	}

	// Bước 4: Xóa mảng tạm đi.
	delete[] tam;
}

void ThemPhanTu(int *&a, int &n, int vitrithem, int phantuthem)
{
	REALLOC(a, n, n + 1);
	for(int i = n - 1; i >= vitrithem; i--)
	{
		a[i + 1] = a[i];
	}
	a[vitrithem] = phantuthem;
	n++;
}

void XoaPhanTu(int *&a, int &n, int vitrixoa)
{
	for(int i = vitrixoa + 1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	REALLOC(a, n, n - 1);
	n--;
}

int main()
{
	int n = 5;

	int *a = new int[n]; // cấp phát bộ nhớ cho con trỏ.

	NhapMang(a, n);
	XuatMang(a, n);

	/*int vitrithem = 2;
	int phantuthem = 69;
	ThemPhanTu(a, n, vitrithem, phantuthem);
	cout << "\nMang sau khi them la: ";
	XuatMang(a, n);*/

	int vitrixoa = 2;
	XoaPhanTu(a, n, vitrixoa);
	cout << "\nMang sau khi xoa la: ";
	XuatMang(a, n);

	cout << "\na[4] = " << a[4];

	// giải phóng tất cả.
	delete []a;

	system("pause");
	return 0;
}