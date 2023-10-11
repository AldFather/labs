#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x; //Вхідний результат
    double y; //результат обчислення виразу
    double A; //стала частина виразу

    // Введення значення x
    cout << "x= "; cin >> x;
    A = 13.5 - 2 * x;
    // спосіб 1: розгалуження в скороченій формі 
    if (x <= -1)
        y = A - exp(0.4 + x);
    if ((x < 1) && (x > -1))
        y = A - 1 - (sin(x) * sin(x));
    if (x >= 1)
        y = A - cos(x) / (1 + sin(x) * sin(x));

    // Виведення результату 1
    cout << "1)y= " << y << endl;

    // спосіб 2: розгалуження в повній формі 
    if (x <= -1)
        y = A - exp(0.4 + x);
    else
        if (x < 1)
            y = A - 1 - (sin(x) * sin(x));
        else
            y = A - cos(x) / (1 + sin(x) * sin(x));
    // Виведення результату 2
    cout << "2)y= " << y << endl;
    cin.get();
    return 0;
}
