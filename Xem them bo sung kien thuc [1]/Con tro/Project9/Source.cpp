#include <iostream>
using namespace std;

void NhapMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "\nNhap vao a[" << i << "] = ";
		cin >> a[i];
		//cin >> *(a + i);
		//cin >> *(a++);
	}
}

void XuatMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << "   ";
		//cout << *(a + i) << "   ";
		//cout << *(a++) << "   ";
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

	int *a = new int[n]; // Cấp phát.
	
	NhapMang(a, n);
	XuatMang(a, n);

	int Tong = TinhTong(a, n);
	printf("\nTong = %d", Tong);

	delete[] a; // Giải phóng mảng con trỏ.
	system("pause");
	return 0;
}