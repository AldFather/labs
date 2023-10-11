// Lab_03_1.cpp
// < Царенко Даниїл >
// Лабораторна робота № 3.1
// Розгалуження, задане формулою: функція однієї змінної.
// Варіант 0.1

#include <iostream>

#include <cmath>

using namespace std;

int main()
{
	double x; // вхідний параметр
	double y; // результат обчислення виразу
	double A; // стала частина виразу

	cout << "x = "; cin >> x;

	A = (x * x) * cos(x / 2);

	// спосіб 1: розгалуження в скороченій формі
	if (x < -5)
		y = A + (x / 5) - exp(abs(x));
	if (-5 <= x && x <= 0)
		y = A + ((x * x * x) / 4) + 1;
	if (x > 0)
		y = A +  1. / tan(log(x));

	cout << endl;
	cout << "1) y = " << y << endl;

	// спосіб 2: розгалуження в повній формі
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