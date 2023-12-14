#pragma execution_character_set("utf-8")
#include <fstream>
#include <iostream>
#include <iomanip> 
#include <string>
#include <Windows.h>
using namespace std;
struct Marshrut {
    string start;
    string finish;
    int nomer;
};
void EnterData(Marshrut* array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << " Маршрут " << i + 1 << ":" << endl;
        cout << "Enter start: ";
        cin >> array[i].start;
        cout << "Enter finish: ";
        cin >> array[i].finish;
        cout << "Enter nomer: ";
        cin >> array[i].nomer;
    }
}

void Print(const Marshrut* array, int size) {
    cout << "=========================================" << endl;
    cout << "|  Початок  |  Кінець  |  Номер маршруту |" << endl;
    cout << "-----------------------------------------" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "| " << setw(7) << left << array[i].start << " | "
            << setw(9) << left << array[i].finish << " | "
            << setw(15) << right << fixed << array[i].nomer << " |" << endl;
    }
    cout << "=========================================" << endl;
}
void SortByMarshrutNomer(Marshrut* array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (array[i].nomer > array[j].nomer) {
                swap(array[i], array[j]);
            }
        }
    }
}
void SearchMarshrutByNomer(const Marshrut* array, int size, const int& nomer) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (array[i].nomer == nomer) {
            cout << "Знайдено маршрут '" << nomer << "':" << endl;
            cout << "Початок: " << array[i].start << ", Кінець: " << array[i].finish  << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Маршрут з номером: '" << nomer << "' не знайдено." << endl;
    }
}

// Функція для зчитування даних з файлу
void LoadFromFile(Marshrut*& p, int& N, const char* filename)
{
    delete[] p;                                   // знищили попередні дані 

    ifstream fin(filename, ios::binary);           // відкрили бінарний файл зчитування 

    fin.read((char*)&N, sizeof(N));                // прочитали кількість елементів 

    p = new Marshrut[N];                          // створили динамічний масив 

    for (int i = 0; i < N; i++)
        fin.read((char*)&p[i], sizeof(Marshrut)); // прочитали елементи масиву 

    fin.close();                                   // закрили файл 
}

// Функція для запису даних у файл
void SaveToFile(Marshrut* p, const int N, const char* filename) {
    ofstream fout(filename, ios::binary);            // відкрили бінарний файл запису 

    fout.write((char*)&N, sizeof(N));                // записали кількість елементів 

    for (int i = 0; i < N; i++)
        fout.write((char*)&p[i], sizeof(Marshrut)); // записали елементи масиву 

    fout.close();                                    // закрили файл 
}
int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int N;
    cout << "Введіть N: "; cin >> N;

    Marshrut* p = new Marshrut[N];

    int found;
    char filename[100];
    int Nomer;

    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << "  [1] - введення даних з клавіатури" << endl;
        cout << "  [2] - вивід даних на екран" << endl;
        cout << "  [3] - фізично впорядкувати масив" << endl;
        cout << "  [4] - пошук маршруту за номером" << endl;
        cout << "  [5] - запис даних у файл" << endl;
        cout << "  [6] - зчитування даних із файлу" << endl << endl;
        cout << "  [0] - вихід та завершення роботи програми" << endl << endl;
        cout << "Введіть значення: "; cin >> menuItem;
        cout << endl << endl << endl;

        switch (menuItem)
        {
        case 1:
            EnterData(p, N);
            break;
        case 2:
            Print(p, N);
            break;
        case 3:
            SortByMarshrutNomer(p, N);

            break;
        case 4:
            cout << "Введіть ключі пошуку:" << endl;
            cin.get();
            cin.sync();

            cout << "    Номер маршруту: "; cin >> Nomer;
            cout << endl;
            SearchMarshrutByNomer(p, N, Nomer);
            break;
        case 5:
            cin.get();
            cin.sync();

            cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
            SaveToFile(p, N, filename);

            break;
        case 6:
            cin.get();
            cin.sync();

            cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
            LoadFromFile(p, N, filename);

            break;
        case 0:
            break;
        default:
            cout << "Ви ввели помилкове значення! "
                "Слід ввести число - номер вибраного пункту меню" << endl;
        }
    } while (menuItem != 0);

    return 0;
}