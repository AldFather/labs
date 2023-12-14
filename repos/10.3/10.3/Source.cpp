#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Marshrut {
    string start;
    string finish;
    double nomer;
};

void createFile(const string& filename, const Marshrut& marshrut) {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Cannot create file." << endl;
        return;
    }
    file << marshrut.start << "," << marshrut.finish << "," << marshrut.nomer << endl;
    file.close();
}

void displayFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Cannot open file" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void addMarshrut(const string& filename, const Marshrut& marshrut) {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Cannot open file for appending." << endl;
        return;
    }

    file << marshrut.start << "," << marshrut.finish << "," << marshrut.nomer << endl;

    file.close();
}

void searchNomer(const string& filename, const double& nomerM) {
    ifstream file(filename);
    if (!file) {
        cerr << "Cannot open file" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {
        stringstream ss(line);
        string start, finish;
        double nomer;

        getline(ss, start, ',');
        getline(ss, finish, ',');
        ss >> nomer;

        if (nomer == nomerM) {
            found = true;
            cout << "Input:" << endl;
            cout << "Start: " << start << endl;
            cout << "Finish: " << finish << endl;
            cout << "Nomer: " << nomer << endl;
            break;
        }
    }

    if (!found) {
        cout << "Nomer not found." << endl;
    }

    file.close();
}

int main() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    Marshrut marshrut;
    int n;
    cout << "N: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter start: ";
        cin >> marshrut.start;
        cout << "Enter finish: ";
        cin >> marshrut.finish;
        cout << "Enter nomer: ";
        cin >> marshrut.nomer;
        createFile(filename, marshrut);
    }


    int choice;
    do {
        cout << "Menu:\n1. Display file content\n2. Add marshrut\n3. Search marshrut\n4. Exit\nEnter marshrut: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayFile(filename);
            break;
        case 2: {
            Marshrut newMarshrut;
            cout << "Enter start: ";
            cin >> newMarshrut.start;
            cout << "Enter finish: ";
            cin >> newMarshrut.finish;
            cout << "Enter nomer: ";
            cin >> newMarshrut.nomer;

            addMarshrut(filename, newMarshrut);
            break;
        }
        case 3: {
            double searchnomer;
            cout << "Enter nomer to search: ";
            cin >> searchnomer;
            searchNomer(filename, searchnomer);
            break;
        }
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter again." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}