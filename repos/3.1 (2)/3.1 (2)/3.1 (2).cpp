// Lab_03_1.cpp
// < ������� ����� >
// ����������� ������ � 3.1
// ������������, ������ ��������: ������� ���� �����.
// ������ 0.1

#include <iostream>

#include <cmath>

using namespace std;

int main()
{
	double x; // ������� ��������
	double y; // ��������� ���������� ������
	double A; // ����� ������� ������

	cout << "x = "; cin >> x;

	A = (x * x) * cos(x / 2);

	// ����� 1: ������������ � ��������� ����
	if (x < -5)
		y = A + (x / 5) - exp(abs(x));
	if (-5 <= x && x <= 0)
		y = A + ((x * x * x) / 4) + 1;
	if (x > 0)
		y = A +  1. / tan(log(x));

	cout << endl;
	cout << "1) y = " << y << endl;

	// ����� 2: ������������ � ����� ����
	if (x < -5)
		y = A + (x / 5) - exp(abs(x));
	else
		if (-5 <= x)
			y = A + ((x * x * x) / 4) + 1;
		else
			y = A + 1. / tan(log(x));

	cout << "2) y = " << y << endl;
	cin.get();

	return 0;
}