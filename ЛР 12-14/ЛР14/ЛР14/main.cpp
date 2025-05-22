#include "parking.h"
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int size;
    cout << "������� ������ ���-�������: ";
    cin >> size;

    HashTable table(size);

    int choice;
    while (true) {
        cout << "\n1 - �������� ���������\n2 - ������� ���������\n3 - ����� ���������\n4 - �������� �������\n0 - �����\n�����: ";
        cin >> choice;

        if (choice == 0) break;

        int place;
        char owner[50];

        switch (choice) {
        case 1:
            cout << "������� ����� �����: ";
            cin >> place;
            cout << "������� ��� ���������: ";
            cin.ignore();
            cin.getline(owner, 50);
            table.insert(place, owner);
            break;
        case 2:
            cout << "������� ����� ����� ��� ��������: ";
            cin >> place;
            table.remove(place);
            break;
        case 3:
            cout << "������� ����� ����� ��� ������: ";
            cin >> place;
            {
                const char* result = table.search(place);
                if (result)
                    cout << "��������: " << result << endl;
                else
                    cout << "����� �� �������.\n";
            }
            break;
        case 4:
            table.print();
            break;
        default:
            cout << "�������� �����.\n";
        }
    }

    return 0;
}
