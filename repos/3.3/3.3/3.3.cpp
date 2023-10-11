// Lab_03_3.cpp
// < прізвище, ім’я автора >
// Лабораторна робота № 3.3
// Розгалуження, задане графіком функції.
// Варіант 0.1
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x; // вхідний аргумент
	double R; // вхідний параметр
	double y; // результат обчислення виразу

	cout << "R = "; cin >> R;

	cout << "x = "; cin >> x;

	// розгалуження в повній формі

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