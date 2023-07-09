#include <iostream>
using namespace std;

void NhapMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "\nNhap vao a[" << i << "] = ";
		cin >> a[i];
	}
}

void XuatMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << "   ";
	}
}

void REALLOC(int *&a, int sizecu, int sizemoi)
{
	int *b = new int[sizecu]; // Tạo ra mảng phụ b

	// Lưu từng phần tử của mảng a sang mảng b.
	for(int i = 0; i < sizecu; i++)
	{
		b[i] = a[i];
	}
	
	delete[] a; // Xóa mảng a đi.
	a = new int[sizemoi]; // Cấp mới lại size cho mảng a.

	// Lưu từng phần tử của mảng b sang mảng a.
	for(int i = 0; i < sizecu; i++)
	{
		a[i] = b[i];
	}

	delete[] b; // Xóa mảng phụ b đi.
}

void ThemPhanTu(int *&a, int &n, int ViTriThem, int PhanTuThem)
{
	// Gia tăng bộ nhớ thêm 1 ô.
	//int *b = new int[n]; // Tạo ra mảng phụ b

	//// Lưu từng phần tử của mảng a sang mảng b.
	//for(int i = 0; i < n; i++)
	//{
	//	b[i] = a[i];
	//}
	//
	//delete[] a; // Xóa mảng a đi.
	//a = new int[n + 1]; // Cấp mới lại mảng a dư ra 1 ô.

	//// Lưu từng phần tử của mảng b sang mảng a.
	//for(int i = 0; i < n; i++)
	//{
	//	a[i] = b[i];
	//}

	//delete[] b; // Xóa mảng phụ b đi.

	REALLOC(a, n, n + 1);

	
	for(int i = n; i >= ViTriThem + 1; i--)
	{
		a[i] = a[i - 1];
	}
	a[ViTriThem] = PhanTuThem;
	n++; // Tăng số lượng phần tử lên.
}

void XoaPhanTu(int *&a, int &n, int ViTriXoa)
{
	for(int i = ViTriXoa; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	n--; // Giảm số lượng phần tử xuống.

	// giảm đi 1 ô.
	//int *b = new int[n]; // Tạo ra mảng phụ b

	//// Lưu từng phần tử của mảng a sang mảng b.
	//for(int i = 0; i < n; i++)
	//{
	//	b[i] = a[i];
	//}
	//
	//delete[] a; // Xóa mảng a đi.
	//a = new int[n]; // Cấp mới lại mảng a dư ra 1 ô.

	//// Lưu từng phần tử của mảng b sang mảng a.
	//for(int i = 0; i < n; i++)
	//{
	//	a[i] = b[i];
	//}

	//delete[] b; // Xóa mảng phụ b đi.

	REALLOC(a, n, n);
}

int main()
{
	int n;

	do{
		cout << "\nNhap vao so luong phan tu cua mang: ";
		cin >> n;

		if(n < 0)
		{
			cout << "\nSo luong phan tu khong hop le. Xin kiem tra lai !";
		}
	}while(n < 0);

	int *a; // Khai báo con trỏ.
	a = new int[n]; // Cấp phát bộ nhớ.

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

	delete[] a; // Giải phóng con trỏ.
	system("pause");
	return 0;
}