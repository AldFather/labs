// Lab_03_2.cpp
// < �������, ��� ������ >
// ����������� ������ � 3.2
// ������������, ������ ��������: ������� � �����������.
// ������ 0.1

#include <iostream>

using namespace std;

int main()
{
	double x; // ������� ��������
	double a; // ������� ��������
	double b; // ������� ��������
	double c; // ������� ��������
	double F; // ��������� ���������� ������
	
	cout << "a = "; cin >> a;
	
	cout << "b = "; cin >> b;

	cout << "c = "; cin >> c;

	cout << "x = "; cin >> x;

	// ����� 1: ������������ � ���������� ����

	if (a < 0 && b != 0)
		F = a * (x * x) - (b * x) + c;
	if (a > 0 && b == 0)
		F = (x - a) / (x - c);
	if (!(a < 0 && b != 0) && !(a > 0 && b == 0))
		F = x / c;
	
	cout << endl;

	cout << "1) F = " << F << endl;

    // ����� 2: ������������ � ������ ����

	if (a < 0 && b != 0)
		F = a * (x * x) - (b * x) + c;
	else 
		if (a > 0 && b == 0)
			F = (x - a) / (x - c);
		else
			F = x / c;

	cout << "2) F = " << F << endl;
	cin.get();
	return 0;
}
