#include <iostream>
using namespace std;

template <typename sondeptrai>
void HoanVi(sondeptrai &a, sondeptrai &b)
{
	sondeptrai Temp = a;
	a = b;
	b = Temp;
}


int main()
{
	char a = 'a', b = 'b';

	HoanVi(a, b);

	cout << "\na = " << a << " & b = " << b;

	system("pause");
	return 0;
}