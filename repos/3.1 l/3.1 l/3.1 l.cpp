// Lab_03_1.cpp
// < Царенко Даниїл >
// Лабораторна робота № 3.1
// Варіант 30

#include <iostream>

#include <cmath>

using namespace std;

int main()
{
	double x; // вхідний параметр
	double y; // результат обчислення виразу
	double A; // стала частина виразу
	double B; // змінна частина виразу

	cout << "x = "; cin >> x;

	A = (x * x) * cos(x / 2);

	// спосіб 1: розгалуження в скороченій формі
	if (x < -5)
		B = (x / 5) - exp(abs(x));
	if (-5 <= x && x <= 0)
		B = ((x * x * x)/4) + 1;
	if (x > 0)
		B = 1./tan(log(x));

	y = A + B;

	cout << endl;
	cout << "1) y = " << y << endl;

	// спосіб 2: розгалуження в повній формі
	if (x < -5)
		B = (x / 5) - exp(abs(x));
	else
		if (-5 <= x && x <= 0)
			B = ((x * x * x) / 4) + 1;
		else
			B = 1. / tan(log(x));

	y = A + B;

	cout << "2) y = " << y << endl;
	cin.get();

	return 0;
}