#include <iostream>

#include <iomanip>

#include <cmath>

using namespace std;
int main()
{
	double x, xp, xk, dx, A, B, y;
    
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	
	cout << fixed;
	cout << "---------------------------" << endl;
	cout << "|" << setw(5) << "x" << " |"
		<< setw(7) << "y" << " |" << endl;
	cout << "---------------------------" << endl;

	x = xp; 
	while (x <= xk)
	{
		A = (x * x) * cos(x / 2);
		if (x < -5)
			B = (x / 5) - exp(abs(x));
		else
			if (-5 <= x && x <= 0)
				B = ((x * x * x) / 4) + 1;
			else
				B = 1. / tan(log(x));

	y = A + B;
	
	cout << "|" << setw(7) << setprecision(2) << x
		<< " |" << setw(10) << setprecision(3) << y
		<< " |" << endl;
	
	x += dx;
	
	}
	cout << "---------------------------" << endl;
	
	return 0;
}