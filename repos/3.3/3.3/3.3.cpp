// Lab_03_3.cpp
// < �������, ��� ������ >
// ����������� ������ � 3.3
// ������������, ������ �������� �������.
// ������ 0.1
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x; // ������� ��������
	double R; // ������� ��������
	double y; // ��������� ���������� ������

	cout << "R = "; cin >> R;

	cout << "x = "; cin >> x;

	// ������������ � ������ ����

	if (x <= -8 - R)
		y = R;
	else
		if (-8 - R < x && x <= 8)
			y = R - sqrt(R * R - x * x);
		else
			if (-8 < x && x <= -8 + R)
				y = R - sqrt(R * R - x * x);
			else
				if (-8 + R < x && x <= -4)
					y = R;
				else
					if (-4 < x && x <= 2)
						y = R + ((-x - 4 - R * x - 4 * R) / 6);
					else
						y = 1 + x;

	cout << endl;
	cout << "y = " << y << endl;

	cin.get();

	return 0;
}