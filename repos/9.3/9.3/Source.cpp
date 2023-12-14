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
        cout << " ������� " << i + 1 << ":" << endl;
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
    cout << "|  �������  |  ʳ����  |  ����� �������� |" << endl;
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
            cout << "�������� ������� '" << nomer << "':" << endl;
            cout << "�������: " << array[i].start << ", ʳ����: " << array[i].finish  << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "������� � �������: '" << nomer << "' �� ��������." << endl;
    }
}

// ������� ��� ���������� ����� � �����
void LoadFromFile(Marshrut*& p, int& N, const char* filename)
{
    delete[] p;                                   // ������� �������� ��� 

    ifstream fin(filename, ios::binary);           // ������� ������� ���� ���������� 

    fin.read((char*)&N, sizeof(N));                // ��������� ������� �������� 

    p = new Marshrut[N];                          // �������� ��������� ����� 

    for (int i = 0; i < N; i++)
        fin.read((char*)&p[i], sizeof(Marshrut)); // ��������� �������� ������ 

    fin.close();                                   // ������� ���� 
}

// ������� ��� ������ ����� � ����
void SaveToFile(Marshrut* p, const int N, const char* filename) {
    ofstream fout(filename, ios::binary);            // ������� ������� ���� ������ 

    fout.write((char*)&N, sizeof(N));                // �������� ������� �������� 

    for (int i = 0; i < N; i++)
        fout.write((char*)&p[i], sizeof(Marshrut)); // �������� �������� ������ 

    fout.close();                                    // ������� ���� 
}
int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int N;
    cout << "������ N: "; cin >> N;

    Marshrut* p = new Marshrut[N];

    int found;
    char filename[100];
    int Nomer;

    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "������� ��:" << endl << endl;
        cout << "  [1] - �������� ����� � ���������" << endl;
        cout << "  [2] - ���� ����� �� �����" << endl;
        cout << "  [3] - ������� ������������ �����" << endl;
        cout << "  [4] - ����� �������� �� �������" << endl;
        cout << "  [5] - ����� ����� � ����" << endl;
        cout << "  [6] - ���������� ����� �� �����" << endl << endl;
        cout << "  [0] - ����� �� ���������� ������ ��������" << endl << endl;
        cout << "������ ��������: "; cin >> menuItem;
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
            cout << "������ ����� ������:" << endl;
            cin.get();
            cin.sync();

            cout << "    ����� ��������: "; cin >> Nomer;
            cout << endl;
            SearchMarshrutByNomer(p, N, Nomer);
            break;
        case 5:
            cin.get();
            cin.sync();

            cout << "������ ��'� �����: "; cin.getline(filename, 99);
            SaveToFile(p, N, filename);

            break;
        case 6:
            cin.get();
            cin.sync();

            cout << "������ ��'� �����: "; cin.getline(filename, 99);
            LoadFromFile(p, N, filename);

            break;
        case 0:
            break;
        default:
            cout << "�� ����� ��������� ��������! "
                "��� ������ ����� - ����� ��������� ������ ����" << endl;
        }
    } while (menuItem != 0);

    return 0;
}