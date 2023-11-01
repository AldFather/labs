// Lab 5_1
#include <iostream>
#include <cmath>
using namespace std;
double h(const double x, const double y, const double z); // прототип
int main()
{
	double a, b;

	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	double c = h(a, -b, 1) + h(2, a + b, abs(a - b));
	cout << "c = " << c << endl;
	return 0;
}
double h(const double x, const double y, const double z) // визначення
{
	return (x * x + x * z - y * z + y * y) / (x * x + abs(x * y * z) + z * z);
}