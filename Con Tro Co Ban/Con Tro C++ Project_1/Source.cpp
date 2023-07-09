#include <iostream>
using namespace std;

void Nhap(int *&n)
{
	n = new int; // cấp phát bộ nhớ.
	cout << "\nNhap vao n = ";
	// scanf("%d", n)
	cin >> *n;
}

void Xuat(int *&n)
{
	// printf("\nn = %d", *n);
	cout << "\nn = " << *n;
	delete n; // giải phóng.
}

int main()
{
	int *n;
	

	Nhap(n);
	Xuat(n);

	

	system("pause");
	return 0;
}