#include <iostream>
#include <iomanip>
#include <time.h> 

using namespace std;

void Create(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        a[i] = rand();
}

double AverageOfOdd(int* a, const int size) {
    int b = 0;
    int c = 0;

    for (int i = 0; i < size; i++) {
        if (a[i] % 2 != 0) {
            b += a[i];
            c++;
        }
    }
        return  b / c;
}

void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i] << " ";
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));
    const int n = 8;
    int a[n];

    Create(a, n);
    Print(a, n);

    double average = AverageOfOdd(a, n);
    
    cout << "Average: " << fixed << setprecision(2) << average << endl;

    return 0;
}