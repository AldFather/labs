#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x; //������� ���������
    double y; //��������� ���������� ������
    double A; //����� ������� ������

    // �������� �������� x
    cout << "x= "; cin >> x;
    A = 13.5 - 2 * x;
    // ����� 1: ������������ � ��������� ���� 
    if (x <= -1)
        y = A - exp(0.4 + x);
    if ((x < 1) && (x > -1))
        y = A - 1 - (sin(x) * sin(x));
    if (x >= 1)
        y = A - cos(x) / (1 + sin(x) * sin(x));

    // ��������� ���������� 1
    cout << "1)y= " << y << endl;

    // ����� 2: ������������ � ����� ���� 
    if (x <= -1)
        y = A - exp(0.4 + x);
    else
        if (x < 1)
            y = A - 1 - (sin(x) * sin(x));
        else
            y = A - cos(x) / (1 + sin(x) * sin(x));
    // ��������� ���������� 2
    cout << "2)y= " << y << endl;
    cin.get();
    return 0;
}
