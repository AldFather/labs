#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;


template <typename T>
void Create(T* a, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

template <typename T>
void Print(T* a, const int size) {
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

template <typename T>
T Sum(T* a, const int size) {
    int suma = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] >= 0) {
            suma += a[i];
        }
    }
    return suma;
}

int main() {
    srand((unsigned)time(NULL));
    int k = 0;
    const int n = 8;
    int a[n];


    int Low = -20;
    int High = 30;

   
    Create(a, n, Low, High);
    Print(a, n);
    cout << "Sum = " << Sum(a, n) << endl;

    return 0;
}