#include <iostream>
#include "stack.h"
using namespace std;

void showMenu() 
{
    cout << "\n����:\n";
    cout << "1. �������� �������\n";
    cout << "2. �������� ����\n";
    cout << "3. �������� ����\n";
    cout << "4. ��������� � ����\n";
    cout << "5. ��������� �� �����\n";
    cout << "6. ������� ������ ��������\n";
    cout << "0. �����\n";
    cout << "�������� �����: ";
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    Stack s;
    int choice, value;

    while (true) 
    {
        showMenu();
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "������� �������� (0 ����� ����������):" << endl;
            while (1)
            {
                cin >> value;
                if (value == 0)
                    break;
                else
                s.push(value);
            }
            break;
        case 2:
            s.print();
            break;
        case 3:
            s.clear();
            cout << "���� ������.\n";
            break;
        case 4:
            s.saveToFile("conservation.txt");
            break;
        case 5:
            s.loadFromFile("conservation.txt");
            break;
        case 6:
            s.removeFirstDuplicate();
            break;
        case 0:
            return 0;
        default:
            cout << "�������� �����!\n";
        }
    }
}