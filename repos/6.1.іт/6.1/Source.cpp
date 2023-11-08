#include <iostream>
#include <iomanip>
#include <time.h> 

using namespace std;


void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}
int Sum(int* a, const int size, int& k) {
    int s = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] > 0 && a[i] % 2 != 0) {
            s += a[i];
            a[i] = 0;
            k++;
        }
    }
    return s;
}

void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));
    int k = 0;
    const int n = 25;
    int a[n];

    int Low = -20;
    int High = 30;

    Create(a, n, Low, High);
    Print(a, n);
    cout << "Sum: " << Sum(a, n, k) << ", Count: " << k << endl;
    Print(a, n);

    return 0;
}